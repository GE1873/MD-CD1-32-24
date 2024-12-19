#include "forest.h"
#include <memory>

Forest::Forest(const std::vector<Tree>& trees) : m_trees{trees}
{
}

size_t Forest::getTreesNumber() const
{
    return m_trees.size();
}

void Forest::growUp(const Tree& tree)
{
    m_trees.push_back(tree);
}

void Forest::cutAll()
{
    m_trees.clear();
}

void Forest::autoPlantForest()
{
    size_t numberOfTrees {static_cast<size_t>(1 + (rand() % 31))};
    for(size_t i{}; i<numberOfTrees; ++i){
        growUp(Tree(static_cast<Tree::TREE_TYPE>(0 + (rand() % 5))));
    }
}

std::vector<Tree> Forest::trees() const
{
    return m_trees;
}
