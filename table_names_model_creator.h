#ifndef TABLENAMESMODELCREATOR_H
#define TABLENAMESMODELCREATOR_H

#include "imodel_creator.h"
#include <QStringListModel>

class TableNamesModelCreator : public IModelCreator {
public:
    explicit TableNamesModelCreator();
    ~TableNamesModelCreator();

    int create_model() override;
    void update_model(const QString& table_name);
};

#endif // TABLENAMESMODELCREATOR_H
