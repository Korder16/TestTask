#ifndef SPLINESERIESCREATOR_H
#define SPLINESERIESCREATOR_H

#include "iseries_creator.h"
#include <QSplineSeries>
#include <QValueAxis>
#include <QDateTimeAxis>
#include <QPointF>
#include <QDebug>
#include <QDateTime>
#include <sql_driver.h>

using namespace QtCharts;

class SplineSeriesCreator : public ISeriesCreator {
public:
    explicit SplineSeriesCreator();
    ~SplineSeriesCreator();

    void create_series() override;
    void fill_series(const QString& table_name) override;
    void update_series(const QString &table_name) override;


    QList<QPointF> list_all_points(QSqlQuery* query);

    QSplineSeries* get_series() const;

    void init_axes();
    void update_x_axis(int first_date, int last_date);
    void update_y_axis(double min_value, double max_value);

    QDateTimeAxis* get_x_axis() const;
    QValueAxis* get_y_axis() const;

private:
    QSplineSeries* series{nullptr};
    SqlDriver* driver{nullptr};

    QDateTimeAxis* x_axis{nullptr};
    QValueAxis* y_axis{nullptr};

};

#endif // SPLINESERIESCREATOR_H
