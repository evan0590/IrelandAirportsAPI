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

    bool create() override { return TAbstractModel::create(); }
    bool update() override { return TAbstractModel::update(); }
    bool save()   override { return TAbstractModel::save(); }
    bool remove() override { return TAbstractModel::remove(); }

    static Departures create(const QString &airport, const QString &airlineName, const QString &flightIata, const QString &flightDate, const QString &departureScheduled, const QString &arrivalAirport, const QString &arrivalScheduled);
    static Departures create(const QVariantMap &values);
    static Departures get(const QString &flightIata);
    static int count();
    static QList<Departures> getAll();
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
