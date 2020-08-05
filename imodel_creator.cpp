#include "imodel_creator.h"

IModelCreator::IModelCreator() {}

IModelCreator::~IModelCreator() {
    delete driver;
    delete model;
}

QAbstractItemModel *IModelCreator::get_model() const {
    if(model != nullptr) {
        return model;
    }
}
