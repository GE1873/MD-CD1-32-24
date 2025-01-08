#ifndef BIRCH_H
#define BIRCH_H

#include "tree.h"


///
/// \brief The Birch class for creating birch tree objects
///
class Birch : public Tree
{
public:
    Birch();
    Birch( const Birch& birch );

    ///
    /// \brief Prints the id, type and name of the tree
    ///
    void wind() const override;

    ///
    /// \brief Gets number of trees
    /// \return
    ///
    static size_t getNumOfTrees();

private:
    inline static size_t _counter{};
};

#endif // BIRCH_H
