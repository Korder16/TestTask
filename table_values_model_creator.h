#ifndef TABLEVALUESMODELCREATOR_H
#define TABLEVALUESMODELCREATOR_H

#include "imodel_creator.h"

class TableValuesModelCreator : public IModelCreator {
public:
    explicit TableValuesModelCreator();
    ~TableValuesModelCreator();

    int create_model() override;
};

#endif // TABLEVALUESMODELCREATOR_H
