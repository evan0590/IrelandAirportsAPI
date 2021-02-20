#include <TreeFrogModel>
#include "arrivals.h"
#include "sqlobjects/arrivalsobject.h"

Arrivals::Arrivals() :
    TAbstractModel(),
    d(new ArrivalsObject())
{
    // set the initial parameters
}

Arrivals::Arrivals(const Arrivals &other) :
    TAbstractModel(),
    d(other.d)
{ }

Arrivals::Arrivals(const ArrivalsObject &object) :
    TAbstractModel(),
    d(new ArrivalsObject(object))
{ }

Arrivals::~Arrivals()
{
    // If the reference count becomes 0,
    // the shared data object 'ArrivalsObject' is deleted.
}

QString Arrivals::airport() const
{
    return d->airport;
}

void Arrivals::setAirport(const QString &airport)
{
    d->airport = airport;
}

QString Arrivals::airlineName() const
{
    return d->airline_name;
}

void Arrivals::setAirlineName(const QString &airlineName)
{
    d->airline_name = airlineName;
}

QString Arrivals::flightIata() const
{
    return d->flight_iata;
}

void Arrivals::setFlightIata(const QString &flightIata)
{
    d->flight_iata = flightIata;
}

QString Arrivals::flightDate() const
{
    return d->flight_date;
}

void Arrivals::setFlightDate(const QString &flightDate)
{
    d->flight_date = flightDate;
}

QString Arrivals::arrivalScheduled() const
{
    return d->arrival_scheduled;
}

void Arrivals::setArrivalScheduled(const QString &arrivalScheduled)
{
    d->arrival_scheduled = arrivalScheduled;
}

QString Arrivals::departureAirport() const
{
    return d->departure_airport;
}

void Arrivals::setDepartureAirport(const QString &departureAirport)
{
    d->departure_airport = departureAirport;
}

QString Arrivals::departureScheduled() const
{
    return d->departure_scheduled;
}

void Arrivals::setDepartureScheduled(const QString &departureScheduled)
{
    d->departure_scheduled = departureScheduled;
}

Arrivals &Arrivals::operator=(const Arrivals &other)
{
    d = other.d;  // increments the reference count of the data
    return *this;
}

Arrivals Arrivals::create(const QString &airport, const QString &airlineName, const QString &flightIata, const QString &flightDate, const QString &arrivalScheduled, const QString &departureAirport, const QString &departureScheduled)
{
    ArrivalsObject obj;
    obj.airport = airport;
    obj.airline_name = airlineName;
    obj.flight_iata = flightIata;
    obj.flight_date = flightDate;
    obj.arrival_scheduled = arrivalScheduled;
    obj.departure_airport = departureAirport;
    obj.departure_scheduled = departureScheduled;
    if (!obj.create()) {
        return Arrivals();
    }
    return Arrivals(obj);
}

Arrivals Arrivals::create(const QVariantMap &values)
{
    Arrivals model;
    model.setProperties(values);
    if (!model.d->create()) {
        model.d->clear();
    }
    return model;
}

Arrivals Arrivals::get(const QString &flightIata)
{
    TSqlORMapper<ArrivalsObject> mapper;
    return Arrivals(mapper.findByPrimaryKey(flightIata));
}

int Arrivals::count()
{
    TSqlORMapper<ArrivalsObject> mapper;
    return mapper.findCount();
}

QList<Arrivals> Arrivals::getAll()
{
    return tfGetModelListByCriteria<Arrivals, ArrivalsObject>(TCriteria());
}

QJsonArray Arrivals::getAllJson()
{
    QJsonArray array;
    TSqlORMapper<ArrivalsObject> mapper;

    if (mapper.find() > 0) {
        for (TSqlORMapperIterator<ArrivalsObject> i(mapper); i.hasNext(); ) {
            array.append(QJsonValue(QJsonObject::fromVariantMap(Arrivals(i.next()).toVariantMap())));
        }
    }
    return array;
}

TModelObject *Arrivals::modelData()
{
    return d.data();
}

const TModelObject *Arrivals::modelData() const
{
    return d.data();
}

QDataStream &operator<<(QDataStream &ds, const Arrivals &model)
{
    auto varmap = model.toVariantMap();
    ds << varmap;
    return ds;
}

QDataStream &operator>>(QDataStream &ds, Arrivals &model)
{
    QVariantMap varmap;
    ds >> varmap;
    model.setProperties(varmap);
    return ds;
}

// Don't remove below this line
T_REGISTER_STREAM_OPERATORS(Arrivals)
