# IrelandAirportsAPI

### Overview
This application has been developed using the 
[AWS SDK for C++](https://aws.amazon.com/sdk-for-cpp/) and the 
[TreeFrog Web Framework](https://www.treefrogframework.org) 
and allows users to retrieve departures and arrivals data from a selection of Irish Airports.

A number of methods are available, each of which will be invoked using HTTP Request (GET method).
Results will be returned in JSON array format.

### Methods
[server] = 'ec2-52-19-19-167.eu-west-1.compute.amazonaws.com'
##### 1. Retrieve All Information
| Method      | http://[server]/[arrivals/departures]                                                     |
|----------   |:------------------------------------------------------------------------------------------|
| Description | Method to retrieve all information from either arrivals or departures table of database.  |
| Parameters  | -   *arrivals/departures* - required, one of the two must be selected.                    |
| Response    | JSON array of all information from either the arrivals or departures table.               |

##### 2. Retrieve Information by Flight IATA
| Method      | http://[server]/[arrivals/departures]/iata/['flight_iata']                                |
|----------   |:------------------------------------------------------------------------------------------|
| Description | Method to retrieve information on a flight by a given flight IATA (Internation Air Transport Association) code. |
| Parameters  | -   *arrivals/departures* - required, one of the two must be selected <br> - *'flight_iata'* - required, flight IATA identifier, is case sensitive, example: FR247. |
| Response    | JSON object containing the information from the relevant row in the selected table. |

##### 3. Retrieve Information on a given Date
| Method      | http://[server]/[arrivals/departures]/date/['yyyy-mm-dd']                                 |
|----------   |:------------------------------------------------------------------------------------------|
| Description | Method to retrieve all information from the selected table of database on a given date.   |
| Parameters  | -   *arrivals/departures* - required, one of the two must be selected <br> - *'yyyy-mm-dd'* - required, date string, example: 2021-02-19. |
| Response    | JSON array of all information from the selected table on a given date.                    |

##### 4. Retrieve Information by Airport
| Method      | http://[server]/[arrivals/departures]/airport/['airport_iata']                            |
|----------   |:------------------------------------------------------------------------------------------|
| Description | Method to retrieve all information from the selected table for a given airport.           |
| Parameters  | -   *arrivals/departures* - required, one of the two must be selected <br> - *'airport_iata'* - required, airport IATA identifier, currently only SNN, ORK and DUB are supported. |
| Response    | JSON array of all information from the selected table for a given airport.                |

##### 5. Retrieve Information by Airline
| Method      | http://[server]/[arrivals/departures]/airline/['airline_name']                            |
|----------   |:------------------------------------------------------------------------------------------|
| Description | Method to retrieve all information from the selected table for a given airline.           |
| Parameters  | -   *arrivals/departures* - required, one of the two must be selected <br> - *'airline_name'* - required, is case sensitive, example: Ryanair. Note: spaces between words can be represented with %20, example: Aer%20Lingus |
| Response    | JSON array of all information from the selected table for a given airline.                |

##### 6. Retrieve Information by Airport on a given Date
| Method      | http://[server]/[arrivals/departures]/airportdate/['airport_iata']/['yyyy-mm-dd']                                                     |
|----------   |:------------------------------------------------------------------------------------------|
| Description | Method to retrieve information from the selected table for a given airport on a given date. |
| Parameters  | -   *arrivals/departures* - required, one of the two must be selected <br> *'airport_iata'>'* - required, airport IATA identifier, currently only SNN, ORK and DUB are supported. <br> - *'yyyy-mm-dd'* - required, date string, example: 2021-02-19. |
| Response    | JSON array of information from the selected table for a given airport on a given date.    |

##### Example query:
http://ec2-52-19-19-167.eu-west-1.compute.amazonaws.com/arrivals/airportdate/SNN/2021-02-19

##### Example response:
```json
[
  {"airlineName": "Turkish Airlines",
  "airport":"Shannon",
  "airportIata":"SNN",
  "arrivalScheduled":"2021-02-19T20:25:00+00:00",
  "departureAirport":"Ataturk Airport",
  "departureScheduled":"2021-02-19T19:00:00+00:00",
  "flightDate":"2021-02-19",
  "flightIata":"TK6567"},
  {"airlineName":"empty",
  "airport":"Shannon",
  "airportIata":"SNN",
  ...}
]
```

