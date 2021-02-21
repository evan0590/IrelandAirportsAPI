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

void ArrivalsController::create()
{
    switch (httpRequest().method())
    {
    case Tf::Get:
        render();
        break;

    case Tf::Post:
    {
        auto arrivals = httpRequest().formItems("arrivals");
        auto model = Arrivals::create(arrivals);

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
            texport(arrivals);
            render();
        }
        break;
    }

    default:
        renderErrorResponse(Tf::NotFound);
        break;
    }
}

void ArrivalsController::save(const QString &flightIata)
{
    switch (httpRequest().method())
    {
    case Tf::Get:
    {
        auto model = Arrivals::getIata(flightIata);
        if (!model.isNull())
        {
            auto arrivals = model.toVariantMap();
            texport(arrivals);
            render();
        }
        break;
    }

    case Tf::Post:
    {
        QString error;
        auto model = Arrivals::getIata(flightIata);

        if (model.isNull())
        {
            error = "Original data not found. It may have been updated/removed by another transaction.";
            tflash(error);
            redirect(urla("save", flightIata));
            break;
        }

        auto arrivals = httpRequest().formItems("arrivals");
        model.setProperties(arrivals);
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
            texport(arrivals);
            render();
        }
        break;
    }

    default:
        renderErrorResponse(Tf::NotFound);
        break;
    }
}

void ArrivalsController::remove(const QString &flightIata)
{
    if (httpRequest().method() != Tf::Post)
    {
        renderErrorResponse(Tf::NotFound);
        return;
    }

    auto arrivals = Arrivals::getIata(flightIata);
    arrivals.remove();
    redirect(urla("index"));
}

// Don't remove below this line
T_DEFINE_CONTROLLER(ArrivalsController)
