#ifndef DEPARTURESCONTROLLER_H
#define DEPARTURESCONTROLLER_H

#include "applicationcontroller.h"

class T_CONTROLLER_EXPORT DeparturesController : public ApplicationController
{
    Q_OBJECT
public:
    DeparturesController() : ApplicationController() {}

public slots:
    void index();

    /* get functions - start */
    void iata(const QString &flightIata);
    void date(const QString &flightDate);
    void airport(const QString &airportIata);
    void airline(const QString &airlineName);
    void airportdate(const QString &airportIata, const QString &flightDate);
    /* get functions - end */

};

#endif // DEPARTURESCONTROLLER_H
