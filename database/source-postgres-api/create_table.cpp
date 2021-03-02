#include <stdio.h>
#include <stdlib.h>
#include "libpq-fe.h"

static void
exit_nicely(PGconn *conn)
{
    PQfinish(conn);
    exit(1);
}

int main(int argc, char **argv)
{
    const char *conninfo;
    const char *createTable;
    PGconn *conn;
    PGresult *res;

    /*
     * The user must supply a parameter on the command line to be used as the conninfo string.
     * example conninfo string: "host = host@endpoint.com user = postgres dbname = airports_database password = password1"
     */
    conninfo = argv[1];

    /* Make a connection to the database */
    conn = PQconnectdb(conninfo);

    /* Check to see that the backend connection was successfully made */
    if (PQstatus(conn) != CONNECTION_OK)
    {
        fprintf(stderr, "Connection to database failed: %s",
                PQerrorMessage(conn));
        exit_nicely(conn);
    }

    /*
     * The user must supply a second parameter on the command line to be used as the createTable string.
     * example createTable string: "CREATE TABLE example(example_id integer primary key, example_text varchar (100));"
     */
    createTable = argv[2];
    res = PQexec(conn, createTable);
    if (PQresultStatus(res) != PGRES_COMMAND_OK)
    {
        fprintf(stderr, "SET failed: %s", PQerrorMessage(conn));
        PQclear(res);
        exit_nicely(conn);
    }

    /* Should PQclear PGresult whenever it is no longer needed to avoid memory leaks */
    PQclear(res);

    /* close the connection to the database and cleanup */
    PQfinish(conn);

    return 0;
}