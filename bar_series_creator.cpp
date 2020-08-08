#include "bar_series_creator.h"

BarSeriesCreator::BarSeriesCreator() {}

BarSeriesCreator::~BarSeriesCreator()
{
    delete series;
}

void BarSeriesCreator::create_series() {
    series = new QBarSeries();

}

void BarSeriesCreator::fill_series(const QString &table_name) {

}

void BarSeriesCreator::update_series(const QString &table_name) {
}


