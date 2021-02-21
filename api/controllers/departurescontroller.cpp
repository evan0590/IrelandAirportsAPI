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

void DeparturesController::create()
{
    switch (httpRequest().method())
    {
    case Tf::Get:
        render();
        break;

    case Tf::Post:
    {
        auto departures = httpRequest().formItems("departures");
        auto model = Departures::create(departures);

        if (!model.isNull())
        {
            QString notice = "Created successfully.";
            tflash(notice);
            redirect(urla("show", model.flightIata()));
        }
        else
        {
            QString error = "Failed to create.";
            texport(error);
            texport(departures);
            render();
        }
        break;
    }

    default:
        renderErrorResponse(Tf::NotFound);
        break;
    }
}

void DeparturesController::save(const QString &flightIata)
{
    switch (httpRequest().method())
    {
    case Tf::Get:
    {
        auto model = Departures::getIata(flightIata);
        if (!model.isNull())
        {
            auto departures = model.toVariantMap();
            texport(departures);
            render();
        }
        break;
    }

    case Tf::Post:
    {
        QString error;
        auto model = Departures::getIata(flightIata);

        if (model.isNull())
        {
            error = "Original data not found. It may have been updated/removed by another transaction.";
            tflash(error);
            redirect(urla("save", flightIata));
            break;
        }

        auto departures = httpRequest().formItems("departures");
        model.setProperties(departures);
        if (model.save())
        {
            QString notice = "Updated successfully.";
            tflash(notice);
            redirect(urla("show", model.flightIata()));
        }
        else
        {
            error = "Failed to update.";
            texport(error);
            texport(departures);
            render();
        }
        break;
    }

    default:
        renderErrorResponse(Tf::NotFound);
        break;
    }
}

void DeparturesController::remove(const QString &flightIata)
{
    if (httpRequest().method() != Tf::Post)
    {
        renderErrorResponse(Tf::NotFound);
        return;
    }

    auto departures = Departures::getIata(flightIata);
    departures.remove();
    redirect(urla("index"));
}

// Don't remove below this line
T_DEFINE_CONTROLLER(DeparturesController)
