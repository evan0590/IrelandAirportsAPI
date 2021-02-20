#ifndef DEPARTURESOBJECT_H
#define DEPARTURESOBJECT_H

#include <TSqlObject>
#include <QSharedData>


class T_MODEL_EXPORT DeparturesObject : public TSqlObject, public QSharedData
{
public:
    QString airport;
    QString airline_name;
    QString flight_iata;
    QString flight_date;
    QString departure_scheduled;
    QString arrival_airport;
    QString arrival_scheduled;

    enum PropertyIndex {
        Airport = 0,
        AirlineName,
        FlightIata,
        FlightDate,
        DepartureScheduled,
        ArrivalAirport,
        ArrivalScheduled,
    };

    int primaryKeyIndex() const override { return FlightIata; }
    int autoValueIndex() const override { return -1; }
    QString tableName() const override { return QStringLiteral("departures"); }

private:    /*** Don't modify below this line ***/
    Q_OBJECT
    Q_PROPERTY(QString airport READ getairport WRITE setairport)
    T_DEFINE_PROPERTY(QString, airport)
    Q_PROPERTY(QString airline_name READ getairline_name WRITE setairline_name)
    T_DEFINE_PROPERTY(QString, airline_name)
    Q_PROPERTY(QString flight_iata READ getflight_iata WRITE setflight_iata)
    T_DEFINE_PROPERTY(QString, flight_iata)
    Q_PROPERTY(QString flight_date READ getflight_date WRITE setflight_date)
    T_DEFINE_PROPERTY(QString, flight_date)
    Q_PROPERTY(QString departure_scheduled READ getdeparture_scheduled WRITE setdeparture_scheduled)
    T_DEFINE_PROPERTY(QString, departure_scheduled)
    Q_PROPERTY(QString arrival_airport READ getarrival_airport WRITE setarrival_airport)
    T_DEFINE_PROPERTY(QString, arrival_airport)
    Q_PROPERTY(QString arrival_scheduled READ getarrival_scheduled WRITE setarrival_scheduled)
    T_DEFINE_PROPERTY(QString, arrival_scheduled)
};

#endif // DEPARTURESOBJECT_H
