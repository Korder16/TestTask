#include "sql_driver.h"

SqlDriver::SqlDriver() {}

SqlDriver::~SqlDriver() {}


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
    connect_to_db();
    QSqlQuery* query = new QSqlQuery();
    query->exec("SELECT name FROM sqlite_master \
                WHERE type='table' \
                ORDER BY name;");

    QStringList table_names;
    while(query->next()) {
        table_names << query->record().value(0).toString();
    }

    delete query;
    return table_names;
}
