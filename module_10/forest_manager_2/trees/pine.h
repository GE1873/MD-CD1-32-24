#ifndef PINE_H
#define PINE_H

#include "tree.h"

class Pine : public Tree
{
public:
    Pine();
    Pine( const Pine& tree );

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

#endif // PINE_H
