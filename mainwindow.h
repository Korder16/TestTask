#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QStringListModel>
#include <QDebug>
#include "imodel_creator.h"
#include "table_names_model_creator.h"
#include "table_values_model_creator.h"
#include "graphic_model_creator.h"
#include "iseries_creator.h"
#include "spline_series_creator.h"

#include <QtCharts>

using namespace QtCharts;

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void fill_table_names_view();
    void fill_table_values_view();

    void set_table_values_view_column_names();

    void create_chart();
    void set_chart_axes();
    void set_chart_settings();
    void connect_chart_to_spline_series();


private slots:
    void on_table_names_view_clicked(const QModelIndex &index);

private:
    Ui::MainWindow *ui;
    QAbstractItemModel* model{nullptr};

    IModelCreator* model_creator{nullptr};
    ISeriesCreator* series_creator{nullptr};

    QChart* chart{nullptr};

};
#endif // MAINWINDOW_H
