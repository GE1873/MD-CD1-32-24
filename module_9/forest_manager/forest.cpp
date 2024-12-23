#include "forest.h"
#include <memory>

Forest::Forest(std::vector<std::unique_ptr<Tree>>* trees) : m_trees{trees} {}

Forest::~Forest()
{
    if(m_trees){
        if (!m_trees->empty()){
            for (std::unique_ptr<Tree>& tree : *m_trees)
            {
                tree.reset();
            }
            m_trees->clear();
        }
        m_trees = nullptr;
    }
}

size_t Forest::getTreesNumber() const
{
    if(m_trees){
        return m_trees->size();
    } else return 0;
}

void Forest::growUp(std::unique_ptr<Tree> upTree)
{
    m_trees->push_back(std::move(upTree));
}

void Forest::cutAll()
{
    if(m_trees){
        if (!m_trees->empty()){
            for (std::unique_ptr<Tree>& tree : *m_trees)
            {
                tree.reset();
            }
            m_trees->clear();
        }        
    }
}

void Forest::autoPlantForest(size_t numberOfTrees)
{    
    for(size_t i{}; i<numberOfTrees; ++i){
        growUp(std::make_unique<Tree>(static_cast<Tree::TreeType>(0 + (rand() % 5))));
    }
}

std::vector<std::unique_ptr<Tree>>* Forest::trees() const
{
    return m_trees;
}

std::shared_ptr<Forest> Forest::operator+(const std::shared_ptr<Forest> spOther)
{
    if(spOther){
        std::vector<std::unique_ptr<Tree>>* trees1 = this->trees();
        std::vector<std::unique_ptr<Tree>>* trees2 = spOther->trees();
        std::vector<std::unique_ptr<Tree>>* trees3 {new std::vector<std::unique_ptr<Tree>>{}};
        trees3->reserve(trees1->size() + trees2->size());
        trees3->insert(trees3->end(), std::make_move_iterator(trees1->begin()), std::make_move_iterator(trees1->end()));
        trees3->insert(trees3->end(), std::make_move_iterator(trees2->begin()), std::make_move_iterator(trees2->end()));
        trees1->clear();        
        trees2->clear();        
        return std::make_shared<Forest>(trees3);
    }else{
        throw std::invalid_argument("Error : Forest class object is undefined!");
    }
}
