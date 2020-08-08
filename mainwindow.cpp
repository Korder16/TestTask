#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    fill_table_names_view();
    fill_table_values_view();
    create_chart();
}

MainWindow::~MainWindow() {
    delete model;
    delete model_creator;
    delete series_creator;
    delete chart;
    delete ui;
}


// Filling table, which contains list of db tables
void MainWindow::fill_table_names_view() {
    model_creator = new TableNamesModelCreator();

    model_creator->create_model();
    model = static_cast<QStringListModel*>(static_cast<TableNamesModelCreator*>(model_creator)->get_model());

    ui->table_names_view->setModel(model);
    ui->table_names_view->setEditTriggers(QAbstractItemView::NoEditTriggers);
}


// Filling table, which contains table fields
void MainWindow::fill_table_values_view() {
    model_creator = new TableValuesModelCreator();

    model_creator->create_model();
    model = static_cast<QSqlTableModel*>(static_cast<TableValuesModelCreator*>(model_creator)->get_model());

    ui->table_values_view->setModel(model);
    ui->table_values_view->setEditTriggers(QAbstractItemView::NoEditTriggers);
    set_table_values_view_column_names();
}


void MainWindow::set_table_values_view_column_names() {
    QStringList column_names;
    column_names << "Время" << "Значение" << "Группа";
    for(int i = 0; i < 3; ++i) {
        ui->table_values_view->model()->setHeaderData(i, Qt::Horizontal, column_names.at(i));
    }
}


void MainWindow::create_chart() {
    chart = new QChart();
    connect_chart_to_spline_series();
    ui->chart_view->setChart(chart);
    set_chart_settings();
}


void MainWindow::set_chart_axes() {
    QDateTimeAxis* x_axis = static_cast<SplineSeriesCreator*>(series_creator)->get_x_axis();
    QValueAxis* y_axis = static_cast<SplineSeriesCreator*>(series_creator)->get_y_axis();
    chart->setAxisX(x_axis);
    chart->setAxisY(y_axis);
}

void MainWindow::set_chart_settings() {
    chart->setTitle("График");
    set_chart_axes();
}

void MainWindow::connect_chart_to_spline_series() {
    series_creator = new SplineSeriesCreator();
    static_cast<SplineSeriesCreator*>(series_creator)->create_series();
    chart->addSeries(static_cast<SplineSeriesCreator*>(series_creator)->get_series());
}

void MainWindow::on_table_names_view_clicked(const QModelIndex &index) {
    ui->table_values_view->clearSpans();
    ui->chart_view->clearMask();
    QString table_name = index.data().toString();
    static_cast<TableValuesModelCreator*>(model_creator)->update_model(table_name);
    static_cast<SplineSeriesCreator*>(series_creator)->update_series(table_name);
}

