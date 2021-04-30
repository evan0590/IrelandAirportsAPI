#include <TfTest/TfTest>
#include "models/departures.h" //  include the model class

class TestDepartures : public QObject
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

void TestDepartures::getIata_data()
{
    // definition of test data
    QTest::addColumn<QString>("airport");
    QTest::addColumn<QString>("airport_iata");
    QTest::addColumn<QString>("airline_name");
    QTest::addColumn<QString>("flight_iata");
    QTest::addColumn<QString>("flight_date");
    QTest::addColumn<QString>("departure_scheduled");
    QTest::addColumn<QString>("arrival_airport");
    QTest::addColumn<QString>("arrival_scheduled");

    // adding to test data
    QTest::newRow("Test flight IATA") << "Dublin International"
                                      << "DUB"
                                      << "Blue Air"
                                      << "0B156"
                                      << "2021-03-31"
                                      << "2021-03-31T19:10:00+00:00"
                                      << "Henri Coanda International"
                                      << "2021-04-01T00:50:00+00:00";
}

void TestDepartures::getIata()
{
    // acquisition of test data
    QFETCH(QString, airport);
    QFETCH(QString, airport_iata);
    QFETCH(QString, airline_name);
    QFETCH(QString, flight_iata);
    QFETCH(QString, flight_date);
    QFETCH(QString, departure_scheduled);
    QFETCH(QString, arrival_airport);
    QFETCH(QString, arrival_scheduled);

    // logic of the test
    const char test_flight_iata[6] = "0B156";
    Departures departure = Departures::getIata(test_flight_iata); // Getting model flight iata

    // verification of result execution
    QCOMPARE(departure.airport(), airport);
    QCOMPARE(departure.airportIata(), airport_iata);
    QCOMPARE(departure.airlineName(), airline_name);
    QCOMPARE(departure.flightIata(), flight_iata);
    QCOMPARE(departure.flightDate(), flight_date);
    QCOMPARE(departure.departureScheduled(), departure_scheduled);
    QCOMPARE(departure.arrivalAirport(), arrival_airport);
    QCOMPARE(departure.arrivalScheduled(), arrival_scheduled);
}

void TestDepartures::getAirlineName_data()
{
    // definition of test data
    QTest::addColumn<QString>("airline_name");

    // adding to test data
    QTest::newRow("Test airline name") << "Aer Lingus";
}

void TestDepartures::getAirlineName()
{
    // acquisition of test data
    QFETCH(QString, airline_name);

    // logic of the test
    QString test_airline_name = "Aer Lingus";
    QJsonArray departures = Departures::getAirlineName(test_airline_name);

    // verification of result execution
    QCOMPARE(departures.first()
                 .toObject()
                 .value(departures.first()
                            .toObject()
                            .keys()[0]) // grab the airline name of the first element of the array of JSON objects
                 .toString(),
             airline_name);
}

void TestDepartures::getAirportByDate_data()
{
    // definition of test data
    QTest::addColumn<QString>("airport_iata");
    QTest::addColumn<QString>("flight_date");

    // adding to test data
    QTest::newRow("Test airport by flight date") << "DUB"
                                                 << "2021-03-31";
}

void TestDepartures::getAirportByDate()
{
    // acquisition of test data
    QFETCH(QString, airport_iata);
    QFETCH(QString, flight_date);

    // logic of the test
    QString test_airport_iata = "DUB";
    QString test_flight_date = "2021-03-31";
    QJsonArray departures = Departures::getAirportByDate(test_airport_iata, test_flight_date);

    // verification of result execution
    QCOMPARE(departures.first()
                 .toObject()
                 .value(departures.first()
                            .toObject()
                            .keys()[2]) // grab the airport iata of the first element of the array
                 .toString(),
             airport_iata);
    QCOMPARE(departures.first()
                 .toObject()
                 .value(departures.first()
                            .toObject()
                            .keys()[6]) // grab the flight date of the first element of the array
                 .toString(),
             flight_date);
}

TF_TEST_MAIN(TestDepartures)  // specify the class name you created
#include "testdepartures.moc" // charm. Make the extension .moc