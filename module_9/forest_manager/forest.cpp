#include "forest.h"
#include <memory>

Forest::Forest(const std::vector<Tree*> trees) : m_trees{trees}
{
}

size_t Forest::getTreesNumber() const
{
    return m_trees.size();
}

void Forest::growUp(Tree* tree)
{
    m_trees.push_back(tree);
}

void Forest::cutAll()
{
    m_trees.clear();
}

void Forest::autoPlantForest(size_t numberOfTrees)
{    
    for(size_t i{}; i<numberOfTrees; ++i){
        Tree* tree = new Tree(static_cast<Tree::TREE_TYPE>(0 + (rand() % 5)));
        growUp(tree);
        //delete tree;
        //tree = nullptr;
    }
}

std::vector<Tree*> Forest::trees() const
{
    return m_trees;
}

std::shared_ptr<Forest> Forest::operator+(const std::shared_ptr<Forest> other)
{
    if(other){
        std::vector<Tree*> trees1 = this->trees();
        std::vector<Tree*> trees2 = other->trees();
        std::vector<Tree*> trees3{};
        trees3.reserve(trees1.size() + trees2.size());
        trees3.insert(trees3.end(), trees1.begin(), trees1.end());
        trees3.insert(trees3.end(), trees2.begin(), trees2.end());
        return std::make_shared<Forest>(trees3);
    }else{
        throw std::invalid_argument("Error : Forest class object is undefined!");
    }
}
