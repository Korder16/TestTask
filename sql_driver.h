#ifndef SQLDRIVER_H
#define SQLDRIVER_H

#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlTableModel>
#include <QSqlError>
#include <QSqlRecord>
#include <QDebug>

class SqlDriver {
public:
    explicit SqlDriver();
    ~SqlDriver();

    int connect_to_db();
    QStringList get_db_table_names();

private:
    QSqlDatabase db;
};

#endif // SQLDRIVER_H
