#include "table_names_model_creator.h"

TableNamesModelCreator::TableNamesModelCreator() {}

TableNamesModelCreator::~TableNamesModelCreator() {}

int TableNamesModelCreator::create_model() {
    model = new QStringListModel();

    static_cast<QStringListModel*>(model)->setStringList(driver->get_instance()->get_db_table_names());
    return 0;
}

void TableNamesModelCreator::update_model(const QString &table_name) {}

