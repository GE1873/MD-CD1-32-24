#ifndef OAK_H
#define OAK_H

#include "tree.h"

class Oak : public Tree
{
public:
    Oak();
    Oak( const Oak& oak );

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

#endif // OAK_H
