#ifndef FOREST_H
#define FOREST_H

#include "tree.h"
#include <memory>
#include <vector>

class Forest
{
public:
    Forest() = default;
    Forest(std::vector<std::unique_ptr<Tree>> *trees);
    ~Forest();

    ///
    /// \brief Adds a tree to the forest
    /// \param tree
    ///
    void growUp(std::unique_ptr<Tree>);

    ///
    /// \brief Cutting down all the trees
    void cutAll();

    ///
    /// \brief Automatically plants forest
    ///
    void autoPlantForest(size_t numberOfTree);

    ///
    /// \brief Overloading the "+" operator to merge forests
    /// \param other
    /// \return
    ///
    std::shared_ptr<Forest> operator+(const std::shared_ptr<Forest> other);

    ///
    /// \brief Getters
    /// \return
    ///
    size_t getTreesNumber() const;
    std::vector<std::unique_ptr<Tree> > *trees() const;

private:
    std::vector<std::unique_ptr<Tree>>* m_trees{new std::vector<std::unique_ptr<Tree>>};
};

#endif // FOREST_H
