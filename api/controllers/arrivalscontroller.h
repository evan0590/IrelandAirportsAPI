#ifndef ARRIVALSCONTROLLER_H
#define ARRIVALSCONTROLLER_H

#include "applicationcontroller.h"

class T_CONTROLLER_EXPORT ArrivalsController : public ApplicationController
{
    Q_OBJECT
public:
    ArrivalsController() : ApplicationController() {}

public slots:
    void index();

    /* get functions - start */
    void iata(const QString &flightIata);
    void date(const QString &flightDate);
    void airport(const QString &airportIata);
    void airline(const QString &airlineName);
    void airportdate(const QString &airportIata, const QString &flightDate);
    /* get functions - end */

    void create();
    void save(const QString &flightIata);
    void remove(const QString &flightIata);
};

#endif // ARRIVALSCONTROLLER_H
