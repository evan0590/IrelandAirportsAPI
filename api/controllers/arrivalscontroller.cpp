#include "arrivalscontroller.h"
#include "arrivals.h"

void ArrivalsController::index()
{
    renderJson(Arrivals::getAllJson());
}

/* get functions - start */
void ArrivalsController::iata(const QString &flightIata)
{
    Arrivals arrival = Arrivals::getIata(flightIata);
    renderJson(arrival.toVariantMap());
}

void ArrivalsController::date(const QString &flightDate)
{
    renderJson(Arrivals::getDate(flightDate));
}

void ArrivalsController::airport(const QString &airportIata)
{
    renderJson(Arrivals::getAirportIata(airportIata));
}

void ArrivalsController::airline(const QString &airlineName)
{
    renderJson(Arrivals::getAirlineName(airlineName));
}

void ArrivalsController::airportdate(const QString &airportIata, const QString &flightDate)
{
    renderJson(Arrivals::getAirportByDate(airportIata, flightDate));
}
/* get functions - end */

// Don't remove below this line
T_DEFINE_CONTROLLER(ArrivalsController)
