#ifndef DECIDUOUSFOREST_H
#define DECIDUOUSFOREST_H

#include "forest.h"

class DeciduousForest : public Forest
{
public:    
    ~DeciduousForest();

    ///
    /// \brief Adds a tree to the forest
    /// \param upTree
    ///
    void growUp( Tree* tree ) override;
};

#endif // DECIDUOUSFOREST_H
