#ifndef SQLDRIVER_H
#define SQLDRIVER_H

#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlTableModel>
#include <QSqlError>
#include <QSqlField>
#include <QSqlRecord>
#include <QDebug>

class SqlDriver {
public:

    static SqlDriver* get_instance();

    int connect_to_db();
    QStringList get_db_table_names();

    const QSqlQuery* get_table_values_query(const QString& table_name);

    QSqlQuery* get_values_to_series(const QString& table_name);

    double get_min_value(const QString& table_name) const;
    double get_max_value(const QString& table_name) const;

    int get_first_date(const QString& table_name) const;
    int get_last_date(const QString& table_name) const;

private:
    static SqlDriver * p_instance;

    SqlDriver();
    ~SqlDriver();
    SqlDriver(const SqlDriver&);
    SqlDriver& operator=( SqlDriver& );

    QSqlDatabase db;
    static QSqlQuery* query;
};

#endif // SQLDRIVER_H
