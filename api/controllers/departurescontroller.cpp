#include "departurescontroller.h"
#include "departures.h"

void DeparturesController::index()
{
    // auto departuresList = Departures::getAll();
    // texport(departuresList);
    // render();
    renderJson(Departures::getAllJson());
}

void DeparturesController::show(const QString &flightIata)
{
    auto departures = Departures::get(flightIata);
    texport(departures);
    render();
}

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
        auto model = Departures::get(flightIata);
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
        auto model = Departures::get(flightIata);

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

    auto departures = Departures::get(flightIata);
    departures.remove();
    redirect(urla("index"));
}

// Don't remove below this line
T_DEFINE_CONTROLLER(DeparturesController)
