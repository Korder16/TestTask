#include "table_names_model_creator.h"

TableNamesModelCreator::TableNamesModelCreator() {}

TableNamesModelCreator::~TableNamesModelCreator() {}

int TableNamesModelCreator::create_model() {
    model = new QStringListModel();
    driver = new SqlDriver();

    static_cast<QStringListModel*>(model)->setStringList(driver->get_db_table_names());
    return 0;
}

