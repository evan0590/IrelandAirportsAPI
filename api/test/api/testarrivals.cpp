#include <TfTest/TfTest>
#include "models/arrivals.h" //  include the model class
#include <iostream>
#include <QDebug>

class TestArrivals : public QObject
{
    Q_OBJECT
private slots:
    void getIata_data();
    void getIata();
    void getAirlineName_data();
    void getAirlineName();
    void getAirportByDate_data();
    void getAirportByDate();
};

void TestArrivals::getIata_data()
{
    // definition of test data
    QTest::addColumn<QString>("airport");
    QTest::addColumn<QString>("airport_iata");
    QTest::addColumn<QString>("airline_name");
    QTest::addColumn<QString>("flight_iata");
    QTest::addColumn<QString>("flight_date");
    QTest::addColumn<QString>("arrival_scheduled");
    QTest::addColumn<QString>("departure_airport");
    QTest::addColumn<QString>("departure_scheduled");

    // adding to test data
    QTest::newRow("Test flight IATA") << "Dublin International"
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

void TestArrivals::getAirlineName_data()
{
    // definition of test data
    QTest::addColumn<QString>("airline_name");

    // adding to test data
    QTest::newRow("Test airline name") << "Aer Lingus";
}

void TestArrivals::getAirlineName()
{
    // acquisition of test data
    QFETCH(QString, airline_name);

    // logic of the test
    QString test_airline_name = "Aer Lingus";
    QJsonArray arrivals = Arrivals::getAirlineName(test_airline_name);

    // verification of result execution
    QCOMPARE(arrivals.first()
                 .toObject()
                 .value(arrivals.first()
                            .toObject()
                            .keys()[0]) // grab the airline name of the first element of the array of JSON objects
                 .toString(),
             airline_name);
}

void TestArrivals::getAirportByDate_data()
{
    // definition of test data
    QTest::addColumn<QString>("airport_iata");
    QTest::addColumn<QString>("flight_date");

    // adding to test data
    QTest::newRow("Test airport by flight date") << "SNN"
                                                 << "2021-02-20";
}

void TestArrivals::getAirportByDate()
{
    // acquisition of test data
    QFETCH(QString, airport_iata);
    QFETCH(QString, flight_date);

    // logic of the test
    QString test_airport_iata = "SNN";
    QString test_flight_date = "2021-02-20";
    QJsonArray arrivals = Arrivals::getAirportByDate(test_airport_iata, test_flight_date);

    // verification of result execution
    QCOMPARE(arrivals.first()
                 .toObject()
                 .value(arrivals.first()
                            .toObject()
                            .keys()[2]) // grab the airport iata of the first element of the array
                 .toString(),
             airport_iata);
    QCOMPARE(arrivals.first()
                 .toObject()
                 .value(arrivals.first()
                            .toObject()
                            .keys()[6]) // grab the flight date of the first element of the array
                 .toString(),
             flight_date);
}

TF_TEST_MAIN(TestArrivals)  // specify the class name you created
#include "testarrivals.moc" // charm. Make the extension .moc