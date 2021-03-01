#ifndef DEPARTURES_H
#define DEPARTURES_H

#include <QStringList>
#include <QDateTime>
#include <QVariant>
#include <QSharedDataPointer>
#include <TGlobal>
#include <TAbstractModel>

class TModelObject;
class DeparturesObject;
class QJsonArray;

class T_MODEL_EXPORT Departures : public TAbstractModel
{
public:
    Departures();
    Departures(const Departures &other);
    Departures(const DeparturesObject &object);
    ~Departures();

    QString airport() const;
    void setAirport(const QString &airport);
    QString airportIata() const;
    void setAirportIata(const QString &airportIata);
    QString airlineName() const;
    void setAirlineName(const QString &airlineName);
    QString flightIata() const;
    void setFlightIata(const QString &flightIata);
    QString flightDate() const;
    void setFlightDate(const QString &flightDate);
    QString departureScheduled() const;
    void setDepartureScheduled(const QString &departureScheduled);
    QString arrivalAirport() const;
    void setArrivalAirport(const QString &arrivalAirport);
    QString arrivalScheduled() const;
    void setArrivalScheduled(const QString &arrivalScheduled);
    Departures &operator=(const Departures &other);

    /* get functions - start */
    static Departures getIata(const QString &flightIata);
    static QJsonArray getAirportIata(const QString &airportIata);
    static QJsonArray getAirlineName(const QString &airlineName);
    static QJsonArray getDate(const QString &flightDate);
    static QJsonArray getAirportByDate(const QString &airportIata, const QString &flightDate);
    /* get functions - end */

    static QJsonArray getAllJson();

private:
    QSharedDataPointer<DeparturesObject> d;

    TModelObject *modelData() override;
    const TModelObject *modelData() const override;
    friend QDataStream &operator<<(QDataStream &ds, const Departures &model);
    friend QDataStream &operator>>(QDataStream &ds, Departures &model);
};

Q_DECLARE_METATYPE(Departures)
Q_DECLARE_METATYPE(QList<Departures>)

#endif // DEPARTURES_H
