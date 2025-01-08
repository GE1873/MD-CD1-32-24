#ifndef CONIFEROUSFOREST_H
#define CONIFEROUSFOREST_H

#include "forest.h"

class ConiferousForest : public Forest
{
public:
    ///
    /// \brief Adds a tree to the forest
    /// \param upTree
    ///
    void growUp( Tree* tree ) override;
};

#endif // CONIFEROUSFOREST_H
