#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    fill_table_names_view();
    fill_table_values_view();
}

MainWindow::~MainWindow() {
    delete model;
    delete ui;
}

// Filling table, which contains list of db tables
void MainWindow::fill_table_names_view() {
    model_creator = new TableNamesModelCreator();

    model_creator->create_model();
    model = static_cast<QStringListModel*>(static_cast<TableNamesModelCreator*>(model_creator)->get_model());

    ui->table_names_view->setModel(model);

    // доделать
//    ui->table_names_view.set
}

// Filling table, which contains table fields
void MainWindow::fill_table_values_view() {
    model_creator = new TableValuesModelCreator();

    model_creator->create_model();
    model = static_cast<QSqlTableModel*>(static_cast<TableValuesModelCreator*>(model_creator)->get_model());

    ui->table_values_view->setModel(model);
}
