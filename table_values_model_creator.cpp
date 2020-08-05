#include "table_values_model_creator.h"

TableValuesModelCreator::TableValuesModelCreator() {}

TableValuesModelCreator::~TableValuesModelCreator() {}

int TableValuesModelCreator::create_model() {
    model = new QSqlTableModel();

    static_cast<QSqlTableModel*>(model)->setTable("data12");
    static_cast<QSqlTableModel*>(model)->select();

    return 0;
}
