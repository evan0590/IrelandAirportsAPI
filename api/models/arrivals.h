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
    Arrivals(const ArrivalsObject &object);
    ~Arrivals();

    QString airport() const;
    void setAirport(const QString &airport);
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

    bool create() override { return TAbstractModel::create(); }
    bool update() override { return TAbstractModel::update(); }
    bool save()   override { return TAbstractModel::save(); }
    bool remove() override { return TAbstractModel::remove(); }

    static Arrivals create(const QString &airport, const QString &airlineName, const QString &flightIata, const QString &flightDate, const QString &arrivalScheduled, const QString &departureAirport, const QString &departureScheduled);
    static Arrivals create(const QVariantMap &values);
    static Arrivals get(const QString &flightIata);
    static int count();
    static QList<Arrivals> getAll();
    static QJsonArray getAllJson();

private:
    QSharedDataPointer<ArrivalsObject> d;

    TModelObject *modelData() override;
    const TModelObject *modelData() const override;
    friend QDataStream &operator<<(QDataStream &ds, const Arrivals &model);
    friend QDataStream &operator>>(QDataStream &ds, Arrivals &model);
};

Q_DECLARE_METATYPE(Arrivals)
Q_DECLARE_METATYPE(QList<Arrivals>)

#endif // ARRIVALS_H
