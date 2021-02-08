#include <iostream>

#include <cpr/cpr.h>
#include <json.hpp>

int main(int argc, char **argv)
{

    cpr::Response response = cpr::Get(cpr::Url{"http://api.aviationstack.com/v1/flights"},
                                      cpr::Parameters{{"access_key", <include_api_key_here>},
                                                      {"dep_iata", <include_airport_iata_here>}});
    auto json = nlohmann::json::parse(response.text);
    std::cout << json.dump(4) << std::endl;
}

/*
 {
    "data": [
        {
            "aircraft": null,
            "airline": {
                "iata": "LX",
                "icao": "SWR",
                "name": "SWISS"
            },
            "arrival": {
                "actual": null,
                "actual_runway": null,
                "airport": "Castellon",
                "baggage": null,
                "delay": null,
                "estimated": "2021-02-08T15:45:00+00:00",
                "estimated_runway": null,
                "gate": null,
                "iata": "CDT",
                "icao": "LECH",
                "scheduled": "2021-02-08T15:45:00+00:00",
                "terminal": null,
                "timezone": "Europe/Madrid"
            },
            "departure": {
                "actual": null,
                "actual_runway": null,
                "airport": "Shannon",
                "delay": 65,
                "estimated": "2021-02-08T12:15:00+00:00",
                "estimated_runway": null,
                "gate": null,
                "iata": "SNN",
                "icao": "EINN",
                "scheduled": "2021-02-08T12:15:00+00:00",
                "terminal": null,
                "timezone": "Europe/Dublin"
            },
            "flight": {
                "codeshared": null,
                "iata": "LX5180",
                "icao": "SWR5180",
                "number": "5180"
            },
            "flight_date": "2021-02-08",
            "flight_status": "scheduled",
            "live": null
        },
        {
            "aircraft": null,
            "airline": {
                "iata": "TK",
                "icao": "THY",
                "name": "Turkish Airlines"
            },
            "arrival": {
                "actual": null,
                "actual_runway": null,
                "airport": "John F Kennedy International",
                "baggage": null,
                "delay": null,
                "estimated": "2021-02-08T09:20:00+00:00",
                "estimated_runway": null,
                "gate": null,
                "iata": "JFK",
                "icao": "KJFK",
                "scheduled": "2021-02-08T09:20:00+00:00",
                "terminal": "1",
                "timezone": "America/New_York"
            },
            "departure": {
                "actual": null,
                "actual_runway": null,
                "airport": "Shannon",
                "delay": null,
                "estimated": "2021-02-08T07:05:00+00:00",
                "estimated_runway": null,
                "gate": null,
                "iata": "SNN",
                "icao": "EINN",
                "scheduled": "2021-02-08T07:05:00+00:00",
                "terminal": null,
                "timezone": "Europe/Dublin"
            },
            "flight": {
                "codeshared": null,
                "iata": "TK6363",
                "icao": "THY6363",
                "number": "6363"
            },
            "flight_date": "2021-02-08",
            "flight_status": "unknown",
            "live": null
        },
        {
            "aircraft": {
                "iata": "B744",
                "icao": "B744",
                "icao24": "4B846D",
                "registration": "TC-ACM"
            },
            "airline": {
                "iata": "TK",
                "icao": "THY",
                "name": "Turkish Airlines"
            },
            "arrival": {
                "actual": null,
                "actual_runway": null,
                "airport": "John F Kennedy International",
                "baggage": null,
                "delay": 290,
                "estimated": "2021-02-07T15:55:00+00:00",
                "estimated_runway": null,
                "gate": null,
                "iata": "JFK",
                "icao": "KJFK",
                "scheduled": "2021-02-07T15:55:00+00:00",
                "terminal": "4",
                "timezone": "America/New_York"
            },
            "departure": {
                "actual": "2021-02-07T19:55:00+00:00",
                "actual_runway": "2021-02-07T19:55:00+00:00",
                "airport": "Shannon",
                "delay": 401,
                "estimated": "2021-02-07T13:15:00+00:00",
                "estimated_runway": "2021-02-07T19:55:00+00:00",
                "gate": null,
                "iata": "SNN",
                "icao": "EINN",
                "scheduled": "2021-02-07T13:15:00+00:00",
                "terminal": null,
                "timezone": "Europe/Dublin"
            },
            "flight": {
                "codeshared": null,
                "iata": "TK6567",
                "icao": "THY6567",
                "number": "6567"
            },
            "flight_date": "2021-02-07",
            "flight_status": "diverted",
            "live": {
                "altitude": 10972.8,
                "direction": 229.1,
                "is_ground": false,
                "latitude": 42.87,
                "longitude": -71.56,
                "speed_horizontal": 769.356,
                "speed_vertical": 0,
                "updated": "2021-02-08T02:14:00+00:00"
            }
        },
        {
            "aircraft": {
                "iata": "B744",
                "icao": "B744",
                "icao24": "4B8472",
                "registration": "TC-ACR"
            },
            "airline": {
                "iata": "TK",
                "icao": "THY",
                "name": "Turkish Airlines"
            },
            "arrival": {
                "actual": null,
                "actual_runway": null,
                "airport": "Chicago O'hare International",
                "baggage": null,
                "delay": 154,
                "estimated": "2021-02-07T18:15:00+00:00",
                "estimated_runway": null,
                "gate": null,
                "iata": "ORD",
                "icao": "KORD",
                "scheduled": "2021-02-07T18:15:00+00:00",
                "terminal": "3",
                "timezone": "America/Chicago"
            },
            "departure": {
                "actual": "2021-02-07T19:41:00+00:00",
                "actual_runway": "2021-02-07T19:41:00+00:00",
                "airport": "Shannon",
                "delay": 221,
                "estimated": "2021-02-07T16:00:00+00:00",
                "estimated_runway": "2021-02-07T19:41:00+00:00",
                "gate": null,
                "iata": "SNN",
                "icao": "EINN",
                "scheduled": "2021-02-07T16:00:00+00:00",
                "terminal": null,
                "timezone": "Europe/Dublin"
            },
            "flight": {
                "codeshared": null,
                "iata": "TK6551",
                "icao": "THY6551",
                "number": "6551"
            },
            "flight_date": "2021-02-07",
            "flight_status": "scheduled",
            "live": {
                "altitude": 9448.8,
                "direction": 312.08,
                "is_ground": false,
                "latitude": 53.75,
                "longitude": -10.55,
                "speed_horizontal": 848.376,
                "speed_vertical": 0,
                "updated": "2021-02-07T20:03:59+00:00"
            }
        }
    ],
    "pagination": {
        "count": 4,
        "limit": 100,
        "offset": 0,
        "total": 4
    }
}
 */