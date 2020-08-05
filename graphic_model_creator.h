#ifndef GRAPHICMODELCREATOR_H
#define GRAPHICMODELCREATOR_H

#include "imodel_creator.h"

class GraphicModelCreator : public IModelCreator {
public:
    explicit GraphicModelCreator();
    ~GraphicModelCreator();

    int create_model() override;
};

#endif // GRAPHICMODELCREATOR_H
