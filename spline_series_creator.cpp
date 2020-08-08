#include "spline_series_creator.h"

SplineSeriesCreator::SplineSeriesCreator() {}

SplineSeriesCreator::~SplineSeriesCreator() {
    delete series;
    delete x_axis;
    delete y_axis;
}


void SplineSeriesCreator::create_series() {
    series = new QSplineSeries();
    init_axes();
    update_series(driver->get_instance()->get_db_table_names().first());
}


void SplineSeriesCreator::fill_series(const QString& table_name) {
    QSqlQuery* query = driver->get_instance()->get_values_to_series(table_name);
    series->replace(list_all_points(query));
}


void SplineSeriesCreator::update_series(const QString &table_name) {
    fill_series(table_name);

    int min_x_axis_value = driver->get_instance()->get_first_date(table_name);
    int max_x_axis_value = driver->get_instance()->get_last_date(table_name);

    update_x_axis(min_x_axis_value, max_x_axis_value);

    double min_y_axis_value = driver->get_instance()->get_min_value(table_name);
    double max_y_axis_value = driver->get_instance()->get_max_value(table_name);

    update_y_axis(min_y_axis_value, max_y_axis_value);
}


QList<QPointF> SplineSeriesCreator::list_all_points(QSqlQuery* query) {
    QList<QPointF> all_points;
    double time_field = 0;
    double value_field = 0;

    while(query->next()) {
        time_field = query->record().value(0).toInt();
        value_field = query->record().value(1).toDouble();
        all_points.append(QPointF(time_field, value_field));
    }

    return all_points;
}


QSplineSeries* SplineSeriesCreator::get_series() const {
    if(series != nullptr) {
        return series;
    }
}

void SplineSeriesCreator::init_axes() {
    x_axis = new QDateTimeAxis();
    y_axis = new QValueAxis();

    x_axis->setFormat("dd-MM-yyyy h:mm");
    x_axis->setTitleText("Время");

    y_axis->setLabelFormat("%.2f");
    y_axis->setTitleText("Значение");
}

void SplineSeriesCreator::update_x_axis(int first_date, int last_date) {
    x_axis->setMin(QDateTime::fromTime_t(first_date));
    x_axis->setMax(QDateTime::fromTime_t(last_date));
}

void SplineSeriesCreator::update_y_axis(double min_value, double max_value) {
    y_axis->setRange(min_value, max_value);
}

QDateTimeAxis* SplineSeriesCreator::get_x_axis() const {
    return x_axis;
}

QValueAxis* SplineSeriesCreator::get_y_axis() const {
    return y_axis;
}




