#include <TfTest/TfTest>
#include "models/arrivals.h" //  include the model class
#include <iostream>

class TestArrivals : public QObject
{
    Q_OBJECT
private slots:
    void getIata_data();
    void getIata();
    void getDate_data();
    void getDate();
};

void TestArrivals::getIata_data()
{
    QTest::addColumn<QString>("airport");
    QTest::addColumn<QString>("airport_iata");
    QTest::addColumn<QString>("airline_name");
    QTest::addColumn<QString>("flight_iata");
    QTest::addColumn<QString>("flight_date");
    QTest::addColumn<QString>("arrival_scheduled");
    QTest::addColumn<QString>("departure_airport");
    QTest::addColumn<QString>("departure_scheduled");

    // adding to test data
    QTest::newRow("No1") << "Dublin International"
                         << "DUB"
                         << "Blue Air"
                         << "0B155"
                         << "2021-02-20"
                         << "2021-02-20T09:15:00+00:00"
                         << "Henri Coanda International"
                         << "2021-02-20T07:15:00+00:00";
}

void TestArrivals::getIata()
{
    // acquisition of test data
    QFETCH(QString, airport);
    QFETCH(QString, airport_iata);
    QFETCH(QString, airline_name);
    QFETCH(QString, flight_iata);
    QFETCH(QString, flight_date);
    QFETCH(QString, arrival_scheduled);
    QFETCH(QString, departure_airport);
    QFETCH(QString, departure_scheduled);

    // logic of the test
    const char test_flight_iata[6] = "0B155";
    Arrivals arrival = Arrivals::getIata(test_flight_iata); // Getting model flight iata

    // verification of result execution
    QCOMPARE(arrival.airport(), airport);
    QCOMPARE(arrival.airportIata(), airport_iata);
    QCOMPARE(arrival.airlineName(), airline_name);
    QCOMPARE(arrival.flightIata(), flight_iata);
    QCOMPARE(arrival.flightDate(), flight_date);
    QCOMPARE(arrival.arrivalScheduled(), arrival_scheduled);
    QCOMPARE(arrival.departureAirport(), departure_airport);
    QCOMPARE(arrival.departureScheduled(), departure_scheduled);
}

void TestArrivals::getDate_data()
{
    QTest::addColumn<QString>("flight_date");

    QTest::newRow("No2") << "2021-02-20";
}

void TestArrivals::getDate()
{
    QFETCH(QString, flight_date);

    const char test_flight_date[11] = "2021-02-20";
    QJsonArray arrivals = Arrivals::getDate(test_flight_date);

    QCOMPARE(arrivals[0].flightDate(), flight_date)
}

TF_TEST_MAIN(TestArrivals)  // specify the class name you created
#include "testarrivals.moc" // charm. Make the extension .moc