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

std::unique_ptr<Forest> operator+(const std::unique_ptr<Forest> forest1, const std::unique_ptr<Forest> forest2)
{
    if(forest1 && forest2){
        std::vector<Tree> newForestTrees{};
        newForestTrees.reserve(forest1->trees().size() + forest2->trees().size());
        newForestTrees.insert(newForestTrees.end(), forest1->trees().begin(), forest1->trees().end());
        newForestTrees.insert(newForestTrees.end(), forest2->trees().begin(), forest2->trees().end());
        return std::make_unique<Forest>(newForestTrees);
    }else{
        throw std::invalid_argument("forest class object is undefined");
    }
}
