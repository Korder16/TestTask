#include "mainwindow.h"

#include <QApplication>
#include <QTime>
#include <sql_driver.h>

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);

    SqlDriver::get_instance();


    MainWindow w;
    w.show();

    return a.exec();
}
