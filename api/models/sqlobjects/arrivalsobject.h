#ifndef ARRIVALSOBJECT_H
#define ARRIVALSOBJECT_H

#include <TSqlObject>
#include <QSharedData>


class T_MODEL_EXPORT ArrivalsObject : public TSqlObject, public QSharedData
{
public:
    QString airport;
    QString airport_iata;
    QString airline_name;
    QString flight_iata;
    QString flight_date;
    QString arrival_scheduled;
    QString departure_airport;
    QString departure_scheduled;

    enum PropertyIndex {
        Airport = 0,
        AirportIata,
        AirlineName,
        FlightIata,
        FlightDate,
        ArrivalScheduled,
        DepartureAirport,
        DepartureScheduled,
    };

    int primaryKeyIndex() const override { return FlightIata; }
    int autoValueIndex() const override { return -1; }
    QString tableName() const override { return QStringLiteral("arrivals"); }

private:    /*** Don't modify below this line ***/
    Q_OBJECT
    Q_PROPERTY(QString airport READ getairport WRITE setairport)
    T_DEFINE_PROPERTY(QString, airport)
    Q_PROPERTY(QString airport_iata READ getairport_iata WRITE setairport_iata)
    T_DEFINE_PROPERTY(QString, airport_iata)
    Q_PROPERTY(QString airline_name READ getairline_name WRITE setairline_name)
    T_DEFINE_PROPERTY(QString, airline_name)
    Q_PROPERTY(QString flight_iata READ getflight_iata WRITE setflight_iata)
    T_DEFINE_PROPERTY(QString, flight_iata)
    Q_PROPERTY(QString flight_date READ getflight_date WRITE setflight_date)
    T_DEFINE_PROPERTY(QString, flight_date)
    Q_PROPERTY(QString arrival_scheduled READ getarrival_scheduled WRITE setarrival_scheduled)
    T_DEFINE_PROPERTY(QString, arrival_scheduled)
    Q_PROPERTY(QString departure_airport READ getdeparture_airport WRITE setdeparture_airport)
    T_DEFINE_PROPERTY(QString, departure_airport)
    Q_PROPERTY(QString departure_scheduled READ getdeparture_scheduled WRITE setdeparture_scheduled)
    T_DEFINE_PROPERTY(QString, departure_scheduled)
};

#endif // ARRIVALSOBJECT_H
