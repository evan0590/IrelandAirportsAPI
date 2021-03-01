#include <QtCore>
#include <TreeFrogView>
#include "arrivals.h" 
#include "applicationhelper.h"

class T_VIEW_EXPORT arrivals_indexView : public TActionView
{
  Q_OBJECT
public:
  arrivals_indexView() : TActionView() { }
  QString toString();
};

QString arrivals_indexView::toString()
{
  responsebody.reserve(2424);
  responsebody += QStringLiteral("<!DOCTYPE html>\n");
    responsebody += QStringLiteral("<html>\n<head>\n  <meta charset=\"UTF-8\">\n  <title>");
  responsebody += THttpUtility::htmlEscape(controller()->name() + ": " + controller()->activeAction());
  responsebody += QStringLiteral("</title>\n</head>\n<body>\n\n<h1>Listing Arrivals</h1>\n\n");
  responsebody += QVariant(linkTo("Create a new Arrivals", urla("create"))).toString();
  responsebody += QStringLiteral("<br />\n<br />\n<table border=\"1\" cellpadding=\"5\" style=\"border: 1px #d0d0d0 solid; border-collapse: collapse;\">\n  <tr>\n    <th>Airport</th>\n    <th>Airport Iata</th>\n    <th>Airline Name</th>\n    <th>Flight Iata</th>\n    <th>Flight Date</th>\n    <th>Arrival Scheduled</th>\n    <th>Departure Airport</th>\n    <th>Departure Scheduled</th>\n  </tr>\n");
  tfetch(QList<Arrivals>, arrivalsList);
  for (const auto &i : arrivalsList) {
  responsebody += QStringLiteral("  <tr>\n    <td>");
  responsebody += THttpUtility::htmlEscape(i.airport());
  responsebody += QStringLiteral("</td>\n    <td>");
  responsebody += THttpUtility::htmlEscape(i.airportIata());
  responsebody += QStringLiteral("</td>\n    <td>");
  responsebody += THttpUtility::htmlEscape(i.airlineName());
  responsebody += QStringLiteral("</td>\n    <td>");
  responsebody += THttpUtility::htmlEscape(i.flightIata());
  responsebody += QStringLiteral("</td>\n    <td>");
  responsebody += THttpUtility::htmlEscape(i.flightDate());
  responsebody += QStringLiteral("</td>\n    <td>");
  responsebody += THttpUtility::htmlEscape(i.arrivalScheduled());
  responsebody += QStringLiteral("</td>\n    <td>");
  responsebody += THttpUtility::htmlEscape(i.departureAirport());
  responsebody += QStringLiteral("</td>\n    <td>");
  responsebody += THttpUtility::htmlEscape(i.departureScheduled());
  responsebody += QStringLiteral("</td>\n    <td>\n      ");
  responsebody += QVariant(linkTo("Show", urla("show", i.flightIata()))).toString();
  responsebody += QStringLiteral("\n      ");
  responsebody += QVariant(linkTo("Edit", urla("save", i.flightIata()))).toString();
  responsebody += QStringLiteral("\n      ");
  responsebody += QVariant(linkTo("Remove", urla("remove", i.flightIata()), Tf::Post, "confirm('Are you sure?')")).toString();
  responsebody += QStringLiteral("\n    </td>\n  </tr>\n");
  };
  responsebody += QStringLiteral("</table>\n\n</body>\n</html>\n");

  return responsebody;
}

T_DEFINE_VIEW(arrivals_indexView)

#include "arrivals_indexView.moc"
