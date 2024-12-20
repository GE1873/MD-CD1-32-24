#ifndef FOREST_H
#define FOREST_H

#include "tree.h"
#include <memory>
#include <vector>

class Forest
{
public:
    Forest() = default;
    Forest(const std::vector<const Tree *> trees);

    ///
    /// \brief Adds a tree to the forest
    /// \param tree
    ///
    void growUp(const Tree* const tree);

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
    std::vector<const Tree *> trees() const;

private:
    std::vector<const Tree*> m_trees{};
};

#endif // FOREST_H
