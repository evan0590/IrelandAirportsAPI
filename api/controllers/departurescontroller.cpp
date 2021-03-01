#include "departurescontroller.h"
#include "departures.h"

void DeparturesController::index()
{
    renderJson(Departures::getAllJson());
}

/* get functions - start */
void DeparturesController::iata(const QString &flightIata)
{
    Departures departure = Departures::getIata(flightIata);
    renderJson(departure.toVariantMap());
}

void DeparturesController::date(const QString &flightDate)
{
    renderJson(Departures::getDate(flightDate));
}

void DeparturesController::airport(const QString &airportIata)
{
    renderJson(Departures::getAirportIata(airportIata));
}

void DeparturesController::airline(const QString &airlineName)
{
    renderJson(Departures::getAirlineName(airlineName));
}

void DeparturesController::airportdate(const QString &airportIata, const QString &flightDate)
{
    renderJson(Departures::getAirportByDate(airportIata, flightDate));
}
/* get functions - end */

// Don't remove below this line
T_DEFINE_CONTROLLER(DeparturesController)
