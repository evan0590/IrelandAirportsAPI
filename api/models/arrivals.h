#ifndef ARRIVALS_H
#define ARRIVALS_H

#include <QStringList>
#include <QDateTime>
#include <QVariant>
#include <QSharedDataPointer>
#include <TGlobal>
#include <TAbstractModel>

class TModelObject;
class ArrivalsObject;
class QJsonArray;

class T_MODEL_EXPORT Arrivals : public TAbstractModel
{
public:
    Arrivals();
    Arrivals(const Arrivals &other);
    Arrivals(const ArrivalsObject &object); // constructor made from the ORM object
    ~Arrivals();

    QString airport() const; // The following lines are the setter/getter
    void setAirport(const QString &airport);
    QString airportIata() const;
    void setAirportIata(const QString &airportIata);
    QString airlineName() const;
    void setAirlineName(const QString &airlineName);
    QString flightIata() const;
    void setFlightIata(const QString &flightIata);
    QString flightDate() const;
    void setFlightDate(const QString &flightDate);
    QString arrivalScheduled() const;
    void setArrivalScheduled(const QString &arrivalScheduled);
    QString departureAirport() const;
    void setDepartureAirport(const QString &departureAirport);
    QString departureScheduled() const;
    void setDepartureScheduled(const QString &departureScheduled);
    Arrivals &operator=(const Arrivals &other);

    /* get functions - start */
    static Arrivals getIata(const QString &flightIata);                                        // Gets object specified by flight IATA
    static QJsonArray getAirportIata(const QString &airportIata);                              // Gets all model objects specified by airport IATA in JSON style
    static QJsonArray getAirlineName(const QString &airlineName);                              // Gets all model objects specified by airline name in JSON style
    static QJsonArray getDate(const QString &flightDate);                                      // Gets all model objects specified by flight date in JSON style
    static QJsonArray getAirportByDate(const QString &airportIata, const QString &flightDate); // Gets all model objects specified by airport IATA and flight date in JSON style
    /* get functions - end */

    static QJsonArray getAllJson();

private:
    QSharedDataPointer<ArrivalsObject> d; // Holds the pointer of the ORM object

    TModelObject *modelData() override;
    const TModelObject *modelData() const override;
    friend QDataStream &operator<<(QDataStream &ds, const Arrivals &model);
    friend QDataStream &operator>>(QDataStream &ds, Arrivals &model);
};

Q_DECLARE_METATYPE(Arrivals)
Q_DECLARE_METATYPE(QList<Arrivals>)

#endif // ARRIVALS_H
