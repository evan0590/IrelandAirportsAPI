#include <TreeFrogModel>
#include "arrivals.h"
#include "sqlobjects/arrivalsobject.h"

Arrivals::Arrivals() : TAbstractModel(),
                       d(new ArrivalsObject())
{
    // set the initial parameters
}

Arrivals::Arrivals(const Arrivals &other) : TAbstractModel(),
                                            d(other.d)
{
}

Arrivals::Arrivals(const ArrivalsObject &object) : TAbstractModel(),
                                                   d(new ArrivalsObject(object))
{
}

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

QString Arrivals::airportIata() const
{
    return d->airport_iata;
}

void Arrivals::setAirportIata(const QString &airportIata)
{
    d->airport_iata = airportIata;
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
    d = other.d; // increments the reference count of the data
    return *this;
}

/* get functions - start */
Arrivals Arrivals::getIata(const QString &flightIata)
{
    TSqlORMapper<ArrivalsObject> mapper;
    return Arrivals(mapper.findByPrimaryKey(flightIata));
}

QJsonArray Arrivals::getAirportIata(const QString &airportIata)
{
    QJsonArray array;
    TSqlORMapper<ArrivalsObject> mapper;

    if (mapper.findBy(1, airportIata) > 0)
    {
        for (TSqlORMapperIterator<ArrivalsObject> i(mapper); i.hasNext();)
        {
            array.append(QJsonValue(QJsonObject::fromVariantMap(Arrivals(i.next()).toVariantMap())));
        }
    }
    return array;
}

QJsonArray Arrivals::getAirlineName(const QString &airlineName)
{
    QJsonArray array;
    TSqlORMapper<ArrivalsObject> mapper;

    if (mapper.findBy(2, airlineName) > 0)
    {
        for (TSqlORMapperIterator<ArrivalsObject> i(mapper); i.hasNext();)
        {
            array.append(QJsonValue(QJsonObject::fromVariantMap(Arrivals(i.next()).toVariantMap())));
        }
    }
    return array;
}

QJsonArray Arrivals::getDate(const QString &flightDate)
{
    QJsonArray array;
    TSqlORMapper<ArrivalsObject> mapper;

    if (mapper.findBy(4, flightDate) > 0)
    {
        for (TSqlORMapperIterator<ArrivalsObject> i(mapper); i.hasNext();)
        {
            array.append(QJsonValue(QJsonObject::fromVariantMap(Arrivals(i.next()).toVariantMap())));
        }
    }
    return array;
}

// Reading ORM Object by Specifying the Search Criteria - combine and apply multiple conditions
QJsonArray Arrivals::getAirportByDate(const QString &airportIata, const QString &flightDate)
{
    TCriteria crt(ArrivalsObject::AirportIata, airportIata);
    crt.add(ArrivalsObject::FlightDate, TSql::Equal, flightDate); // AND add to the end operator

    QJsonArray array;
    TSqlORMapper<ArrivalsObject> mapper;

    if (mapper.find(crt) > 0)
    {
        for (TSqlORMapperIterator<ArrivalsObject> i(mapper); i.hasNext();)
        {
            array.append(QJsonValue(QJsonObject::fromVariantMap(Arrivals(i.next()).toVariantMap())));
        }
    }
    return array;
}

/* get functions - end */

QJsonArray Arrivals::getAllJson()
{
    QJsonArray array;
    TSqlORMapper<ArrivalsObject> mapper;

    if (mapper.find() > 0)
    {
        for (TSqlORMapperIterator<ArrivalsObject> i(mapper); i.hasNext();)
        {
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
