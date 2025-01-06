#ifndef FOREST_H
#define FOREST_H

#include "../trees/tree.h"
#include <memory>
#include <vector>

///
/// \brief The Forest class for creating and managing forest objects
///
class Forest
{
public:
    ///
    /// \brief Adds a tree to the forest
    /// \param tree
    ///
    virtual void growUp( Tree* tree ) = 0;    

    ///
    /// \brief Prints the id, type and name of the trees in the forest
    ///
    void wind() const;

    ///
    /// \brief Checks if a forest contains a certain tree type
    /// \param type
    /// \return
    ///
    bool isContainTreeType( const TreeNamesGenerator::TreeType type ) const;

protected:
    std::vector<Tree*> _trees{};
};

#endif // FOREST_H
