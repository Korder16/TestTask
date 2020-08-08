#include "table_values_model_creator.h"

TableValuesModelCreator::TableValuesModelCreator() {}

TableValuesModelCreator::~TableValuesModelCreator() {}

int TableValuesModelCreator::create_model() {
    model = new QSqlQueryModel();

    static_cast<QSqlQueryModel*>(model)->setQuery(*driver->get_instance()->get_table_values_query(driver->get_db_table_names().first()));

    return 0;
}

void TableValuesModelCreator::update_model(const QString &table_name) {
    static_cast<QSqlQueryModel*>(model)->setQuery(*driver->get_table_values_query(table_name));
}
