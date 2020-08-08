#ifndef BARSERIESCREATOR_H
#define BARSERIESCREATOR_H

#include "iseries_creator.h"
#include <QBarSeries>
#include <QBarSet>
#include <QValueAxis>
#include <QPointF>
#include <QDebug>
#include <sql_driver.h>

class BarSeriesCreator : public ISeriesCreator {
public:
    BarSeriesCreator();
    ~BarSeriesCreator();

    void create_series() override;
    void fill_series(const QString &table_name) override;
    void update_series(const QString &table_name) override;

private:
    QBarSeries* series{nullptr};
};

#endif // BARSERIESCREATOR_H
