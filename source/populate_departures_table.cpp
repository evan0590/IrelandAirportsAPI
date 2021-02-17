#include <cstring>
#include <fstream>
#include <iostream>
#include <iomanip>
#include <nlohmann/json.hpp>
#include "libpq-fe.h"

using json = nlohmann::json;

static void
exit_nicely(PGconn *conn)
{
    PQfinish(conn);
    exit(1);
}

int main(int argc, char **argv)
{
    const char *airportiata;
    const char *conninfo;
    PGconn *conn;
    PGresult *res;

    /*
     * The user must supply a first parameter on the command line to be used as the airportiata string.
     * example airportiata string: "SNN"
     */
    airportiata = argv[1];
    /*
     * The user must supply a second parameter on the command line to be used as the conninfo string.
     * example conninfo string: "host = host@endpoint.com user = postgres dbname = airports_database password = password1"
     */
    conninfo = argv[2];

    /* Make a connection to the database */
    conn = PQconnectdb(conninfo);

    /*  Convert parameter to string for accessing json file name */
    std::string airportiata_s = airportiata;
    /*  Open the relevant json file and parse the data within */
    std::ifstream file("./json/dep_iata_" + airportiata_s + ".json");
    json j = json::parse(file);
    json parsed = j["data"];

    /* Iterate the parsed data and write the information to the table */
    for (int i = 0; i < parsed.size(); i++)
    {
        /* Retrieve the string value */
        std::string arrival_airport_s = parsed[i]["arrival"]["airport"].get<std::string>();
        std::string departure_airport_s = parsed[i]["departure"]["airport"].get<std::string>();
        std::string airline_name_s = parsed[i]["airline"]["name"].get<std::string>();
        std::string flight_iata_s = parsed[i]["flight"]["iata"].get<std::string>();
        std::string flight_date_s = parsed[i]["flight_date"].get<std::string>();
        std::string arrival_scheduled_s = parsed[i]["arrival"]["scheduled"].get<std::string>();
        std::string departure_scheduled_s = parsed[i]["departure"]["scheduled"].get<std::string>();

        /* SQL command */
        const char command[] = "INSERT INTO departures(airport, airline_name, flight_iata, flight_date, "
                               "departure_scheduled, arrival_airport, arrival_scheduled) "
                               "values($1, $2, $3, $4, $5, $6, $7);";

        /* Parse string values to char arrays */
        char airport[50];
        strcpy(airport, departure_airport_s.c_str());
        airport[departure_airport_s.size()] = '\0';

        char airline_name[100];
        strcpy(airline_name, airline_name_s.c_str());
        airline_name[airline_name_s.size()] = '\0';

        char flight_iata[25];
        strcpy(flight_iata, flight_iata_s.c_str());
        flight_iata[flight_iata_s.size()] = '\0';

        char flight_date[25];
        strcpy(flight_date, flight_date_s.c_str());
        flight_date[flight_date_s.size()] = '\0';

        char departure_scheduled[50];
        strcpy(departure_scheduled, departure_scheduled_s.c_str());
        departure_scheduled[departure_scheduled_s.size()] = '\0';

        char arrival_airport[50];
        strcpy(arrival_airport, arrival_airport_s.c_str());
        arrival_airport[arrival_airport_s.size()] = '\0';

        char arrival_scheduled[50];
        strcpy(arrival_scheduled, arrival_scheduled_s.c_str());
        arrival_scheduled[arrival_scheduled_s.size()] = '\0';

        int nParams = 7;
        const char *const paramValues[7] = {airport, airline_name, flight_iata,
                                            flight_date, departure_scheduled, arrival_airport, arrival_scheduled};
        int paramLengths[7] = {sizeof(airport), sizeof(airline_name), sizeof(flight_iata),
                               sizeof(flight_date), sizeof(arrival_scheduled),
                               sizeof(arrival_airport), sizeof(departure_scheduled)};
        const int paramFormats[] = {0, 0, 0, 0, 0, 0, 0};
        int resultFormat = 0;

        /* PQexecParams */
        res = PQexecParams(conn, command, nParams, NULL, paramValues, paramLengths,
                           paramFormats, resultFormat);
        if (PQresultStatus(res) != PGRES_COMMAND_OK)
        {
            fprintf(stderr, "SET failed: %s", PQerrorMessage(conn));
            PQclear(res);
            exit_nicely(conn);
        }
        PQclear(res);
    }

    /* close the connection to the database and cleanup */
    PQfinish(conn);

    return 0;
}