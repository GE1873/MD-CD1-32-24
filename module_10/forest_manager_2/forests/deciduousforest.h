#ifndef DECIDUOUSFOREST_H
#define DECIDUOUSFOREST_H

#include "forest.h"

///
/// \brief The DeciduousForest class for creating deciduous forest objects
///
class DeciduousForest : public Forest
{
public:
    ///
    /// \brief Adds a tree to the forest
    /// \param upTree
    ///
    void growUp( Tree* tree ) override;
};

#endif // DECIDUOUSFOREST_H
