#ifndef CEDAR_H
#define CEDAR_H

#include "tree.h"

///
/// \brief The Cedar class for creating cedar tree objects
///
class Cedar : public Tree
{
public:
    Cedar();
    Cedar( const Cedar& cedar );

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

#endif // CEDAR_H
