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
    void show(const QString &flightIata);
    void create();
    void save(const QString &flightIata);
    void remove(const QString &flightIata);
};

#endif // ARRIVALSCONTROLLER_H
