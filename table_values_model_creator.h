#ifndef TABLEVALUESMODELCREATOR_H
#define TABLEVALUESMODELCREATOR_H

#include "imodel_creator.h"
#include <QDateTime>

class TableValuesModelCreator : public IModelCreator {
public:
    explicit TableValuesModelCreator();
    ~TableValuesModelCreator();

    int create_model() override;
    void update_model(const QString& table_name) override;
};

#endif // TABLEVALUESMODELCREATOR_H
