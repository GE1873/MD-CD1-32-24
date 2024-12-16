#include "forest.h"
#include <memory>

Forest::Forest(std::vector<Tree> trees) : m_trees{trees}
{    
}

size_t Forest::getTreesNumber()
{
    return m_trees.size();
}

void Forest::growUp(const Tree &tree)
{
    m_trees.push_back(tree);
}

void Forest::cutAll()
{
    m_trees.clear();
}

void Forest::autoPlantForest()
{

}

std::vector<Tree> Forest::trees() const
{
    return m_trees;
}

Forest operator+(const Forest& forest1, const Forest& forest2)
{
    std::vector<Tree> newForestTrees{};
    newForestTrees.reserve(forest1.trees().size() + forest2.trees().size());
    newForestTrees.insert(newForestTrees.end(), forest1.trees().begin(), forest1.trees().end());
    newForestTrees.insert(newForestTrees.end(), forest2.trees().begin(), forest2.trees().end());
    return *new Forest(newForestTrees);
}
