#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QStringListModel>
#include <QDebug>
#include "imodel_creator.h"
#include "table_names_model_creator.h"
#include "table_values_model_creator.h"
#include "graphic_model_creator.h"

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

private:
    Ui::MainWindow *ui;
    QAbstractItemModel* model{nullptr};
//    QStringListModel* table_names_model{nullptr};
//    QSqlTableModel* table_values_model{nullptr};

    IModelCreator* model_creator{nullptr};
};
#endif // MAINWINDOW_H
