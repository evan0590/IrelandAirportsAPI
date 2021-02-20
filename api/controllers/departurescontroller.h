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
    void show(const QString &flightIata);
    void create();
    void save(const QString &flightIata);
    void remove(const QString &flightIata);
};

#endif // DEPARTURESCONTROLLER_H
