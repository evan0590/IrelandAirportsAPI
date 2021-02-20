#include <TreeFrogModel>
#include "departures.h"
#include "sqlobjects/departuresobject.h"

Departures::Departures() :
    TAbstractModel(),
    d(new DeparturesObject())
{
    // set the initial parameters
}

Departures::Departures(const Departures &other) :
    TAbstractModel(),
    d(other.d)
{ }

Departures::Departures(const DeparturesObject &object) :
    TAbstractModel(),
    d(new DeparturesObject(object))
{ }

Departures::~Departures()
{
    // If the reference count becomes 0,
    // the shared data object 'DeparturesObject' is deleted.
}

QString Departures::airport() const
{
    return d->airport;
}

void Departures::setAirport(const QString &airport)
{
    d->airport = airport;
}

QString Departures::airlineName() const
{
    return d->airline_name;
}

void Departures::setAirlineName(const QString &airlineName)
{
    d->airline_name = airlineName;
}

QString Departures::flightIata() const
{
    return d->flight_iata;
}

void Departures::setFlightIata(const QString &flightIata)
{
    d->flight_iata = flightIata;
}

QString Departures::flightDate() const
{
    return d->flight_date;
}

void Departures::setFlightDate(const QString &flightDate)
{
    d->flight_date = flightDate;
}

QString Departures::departureScheduled() const
{
    return d->departure_scheduled;
}

void Departures::setDepartureScheduled(const QString &departureScheduled)
{
    d->departure_scheduled = departureScheduled;
}

QString Departures::arrivalAirport() const
{
    return d->arrival_airport;
}

void Departures::setArrivalAirport(const QString &arrivalAirport)
{
    d->arrival_airport = arrivalAirport;
}

QString Departures::arrivalScheduled() const
{
    return d->arrival_scheduled;
}

void Departures::setArrivalScheduled(const QString &arrivalScheduled)
{
    d->arrival_scheduled = arrivalScheduled;
}

Departures &Departures::operator=(const Departures &other)
{
    d = other.d;  // increments the reference count of the data
    return *this;
}

Departures Departures::create(const QString &airport, const QString &airlineName, const QString &flightIata, const QString &flightDate, const QString &departureScheduled, const QString &arrivalAirport, const QString &arrivalScheduled)
{
    DeparturesObject obj;
    obj.airport = airport;
    obj.airline_name = airlineName;
    obj.flight_iata = flightIata;
    obj.flight_date = flightDate;
    obj.departure_scheduled = departureScheduled;
    obj.arrival_airport = arrivalAirport;
    obj.arrival_scheduled = arrivalScheduled;
    if (!obj.create()) {
        return Departures();
    }
    return Departures(obj);
}

Departures Departures::create(const QVariantMap &values)
{
    Departures model;
    model.setProperties(values);
    if (!model.d->create()) {
        model.d->clear();
    }
    return model;
}

Departures Departures::get(const QString &flightIata)
{
    TSqlORMapper<DeparturesObject> mapper;
    return Departures(mapper.findByPrimaryKey(flightIata));
}

int Departures::count()
{
    TSqlORMapper<DeparturesObject> mapper;
    return mapper.findCount();
}

QList<Departures> Departures::getAll()
{
    return tfGetModelListByCriteria<Departures, DeparturesObject>(TCriteria());
}

QJsonArray Departures::getAllJson()
{
    QJsonArray array;
    TSqlORMapper<DeparturesObject> mapper;

    if (mapper.find() > 0) {
        for (TSqlORMapperIterator<DeparturesObject> i(mapper); i.hasNext(); ) {
            array.append(QJsonValue(QJsonObject::fromVariantMap(Departures(i.next()).toVariantMap())));
        }
    }
    return array;
}

TModelObject *Departures::modelData()
{
    return d.data();
}

const TModelObject *Departures::modelData() const
{
    return d.data();
}

QDataStream &operator<<(QDataStream &ds, const Departures &model)
{
    auto varmap = model.toVariantMap();
    ds << varmap;
    return ds;
}

QDataStream &operator>>(QDataStream &ds, Departures &model)
{
    QVariantMap varmap;
    ds >> varmap;
    model.setProperties(varmap);
    return ds;
}

// Don't remove below this line
T_REGISTER_STREAM_OPERATORS(Departures)