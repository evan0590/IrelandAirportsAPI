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
    const char *conninfo;
    PGconn *conn;
    PGresult *res;

    /*
     * The user must supply a first parameter on the command line to be used as the conninfo string.
     * example conninfo string: "host = host@endpoint.com user = postgres dbname = airports_database password = password1"
     */
    conninfo = argv[1];

    /* Make a connection to the database */
    conn = PQconnectdb(conninfo);

    std::ifstream file("airport.json");
    json j = json::parse(file);
    json parsed = j["data"];

    for (int i = 0; i < j.size(); i++)
    {

        // retrieve the string value
        std::string airport_s = parsed[i]["arrival"]["airport"].get<std::string>();
        std::string airline_name_s = parsed[i]["airline"]["name"].get<std::string>();
        std::string flight_iata_s = parsed[i]["flight"]["iata"].get<std::string>();
        std::string flight_date_s = parsed[i]["flight_date"].get<std::string>();
        std::string arrival_scheduled_s = parsed[i]["arrival"]["scheduled"].get<std::string>();
        std::string departure_airport_s = parsed[i]["departure"]["airport"].get<std::string>();
        std::string departure_scheduled_s = parsed[i]["departure"]["scheduled"].get<std::string>();

        // libpq commands from here
        const char command[] = "INSERT INTO arrivals(airport, airline_name, flight_iata, flight_date, "
                               "arrival_scheduled, departure_airport, departure_scheduled) "
                               "values($1, $2, $3, $4, $5, $6, $7);";

        char airport[50];
        strcpy(airport, airport_s.c_str());
        airport[airport_s.size()] = '\0';

        char airline_name[100];
        strcpy(airline_name, airline_name_s.c_str());
        airline_name[airline_name_s.size()] = '\0';

        char flight_iata[25];
        strcpy(flight_iata, flight_iata_s.c_str());
        flight_iata[flight_iata_s.size()] = '\0';

        char flight_date[25];
        strcpy(flight_date, flight_date_s.c_str());
        flight_date[flight_date_s.size()] = '\0';

        char arrival_scheduled[50];
        strcpy(arrival_scheduled, arrival_scheduled_s.c_str());
        arrival_scheduled[arrival_scheduled_s.size()] = '\0';

        char departure_airport[50];
        strcpy(departure_airport, departure_airport_s.c_str());
        departure_airport[departure_airport_s.size()] = '\0';

        char departure_scheduled[50];
        strcpy(departure_scheduled, departure_scheduled_s.c_str());
        departure_scheduled[departure_scheduled_s.size()] = '\0';

        int nParams = 7;
        const char *const paramValues[7] = {airport, airline_name, flight_iata,
                                            flight_date, arrival_scheduled, departure_airport, departure_scheduled};
        //calculate the lengths of each of the values
        int paramLengths[7] = {sizeof(airport), sizeof(airline_name), sizeof(flight_iata),
                               sizeof(flight_date), sizeof(arrival_scheduled),
                               sizeof(departure_airport), sizeof(departure_scheduled)};
        const int paramFormats[] = {0, 0, 0, 0, 0, 0, 0};
        int resultFormat = 0;

        /* PQexecParams demo */
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