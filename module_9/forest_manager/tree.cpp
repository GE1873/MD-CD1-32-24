#include "tree.h"
#include <iomanip>
#include <iostream>

Tree::Tree(const TREE_TYPE type) : Tree(generateName(type), type) {}

Tree::Tree(const std::string &name, const TREE_TYPE type) : m_name{name}, m_type{type} {}

Tree::Tree(const Tree &tree) : Tree(tree.getName(), tree.getType()) {}

void Tree::wind() const
{
    std::cout << "------------------------------------------------------" << std::endl;
    std::cout << std::left << std::setw(25) << "Tree name is : " << std::setw(25) << m_name << std::endl;
    std::cout << std::left << std::setw(25) << "Tree id is : " << std::setw(25) << m_id << std::endl;
    std::cout << "------------------------------------------------------" << std::endl;
}

std::string Tree::generateName(const TREE_TYPE type) const
{
    std::string res {};
    switch (type) {
    case TREE_TYPE::PINE:
    {
        res = pineTreeNames[0 + (rand() % 3)];
        break;
    }
    case TREE_TYPE::OAK:
    {
        res = oakTreeNames[0 + (rand() % 3)];
        break;
    }
    case TREE_TYPE::MAPLE:
    {
        res = mapleTreeNames[0 + (rand() % 3)];
        break;
    }
    case TREE_TYPE::BIRCH:
    {
        res = birchTreeNames[0 + (rand() % 3)];
        break;
    }
    case TREE_TYPE::ASPEN:
    {
        res = aspenTreeNames[0 + (rand() % 3)];
        break;
    }
    default:
    {
        res = "undefined";
        break;
    }
    }
    return res;
}

Tree::TREE_TYPE Tree::getType() const
{
    return m_type;
}

std::string Tree::getName() const
{
    return m_name;
}

size_t Tree::getId() const
{
    return m_id;
}
