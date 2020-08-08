#include "sql_driver.h"

SqlDriver* SqlDriver::p_instance = nullptr;

QSqlQuery* SqlDriver::query = nullptr;


SqlDriver::SqlDriver() {
    connect_to_db();
    query = new QSqlQuery();
}

SqlDriver::~SqlDriver() {
    delete query;
}


SqlDriver* SqlDriver::get_instance() {
    if(!p_instance) {
        p_instance = new SqlDriver;
    }
    return p_instance;
}

int SqlDriver::connect_to_db() {
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setHostName("127.0.0.1");
    db.setDatabaseName("../sample.db");

    if(!db.open()) {
        qDebug() << db.lastError().text();
        return -1;
    }
    return 0;
}

QStringList SqlDriver::get_db_table_names() {
    query->exec("SELECT name FROM sqlite_master \
                WHERE type='table' \
                ORDER BY name;");

    QStringList table_names;
    while(query->next()) {
        table_names << query->record().value(0).toString();
    }
//    query->next();
    return table_names;
}

const QSqlQuery* SqlDriver::get_table_values_query(const QString& table_name) {
    QString sql_request = "SELECT strftime('%d-%m-%Y %H:%M:%S', datetime(Time, 'unixepoch')), Value, Number \
            FROM " + table_name;
    query->exec(sql_request);

    return query;
}

QSqlQuery* SqlDriver::get_values_to_series(const QString &table_name) {
    QString sql_request = "SELECT Time, Value \
            FROM " + table_name;
    query->exec(sql_request);

    return query;
}


double SqlDriver::get_min_value(const QString &table_name) const {
    QString sql_request = "SELECT MIN(Value) \
            FROM " + table_name;
    query->exec(sql_request);

    query->next();
    double min_value = query->record().value(0).toDouble();

    return min_value;
}

double SqlDriver::get_max_value(const QString &table_name) const {
    QString sql_request = "SELECT MAX(Value) \
            FROM " + table_name;
    query->exec(sql_request);

    query->next();
    double max_value = query->record().value(0).toDouble();

    return max_value;
}


int SqlDriver::get_first_date(const QString &table_name) const {
    QString sql_request = "SELECT MIN(Time) \
            FROM " + table_name;
    query->exec(sql_request);

    query->next();
    int first_date = query->record().value(0).toInt();

    return first_date;
}

int SqlDriver::get_last_date(const QString &table_name) const {
    QString sql_request = "SELECT MAX(Time) \
            FROM " + table_name;
    query->exec(sql_request);

    query->next();
    int last_date = query->record().value(0).toInt();

    return last_date;
}
