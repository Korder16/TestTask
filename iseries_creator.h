#ifndef ISERIESCREATOR_H
#define ISERIESCREATOR_H

#include <QAbstractSeries>

using namespace QtCharts;

class ISeriesCreator {
public:
    explicit ISeriesCreator();
    virtual ~ISeriesCreator();

    virtual void create_series() = 0;
    virtual void fill_series(const QString& table_name) = 0;
    virtual void update_series(const QString& table_name) = 0;
};

#endif // ISERIESCREATOR_H
