#ifndef IMODELCREATOR_H
#define IMODELCREATOR_H

#include "sql_driver.h"

class IModelCreator {
public:
    explicit IModelCreator();
    virtual ~IModelCreator();

    virtual int create_model() = 0;
    virtual void update_model(const QString& table_name) = 0;
    virtual QAbstractItemModel* get_model() const;

protected:
    QAbstractItemModel* model{nullptr};
    SqlDriver* driver{nullptr};
};

#endif // IMODELCREATOR_H
