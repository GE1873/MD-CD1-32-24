#include "tree.h"
#include <iomanip>
#include <iostream>

Tree::Tree(const TREE_TYPE type) : Tree(generateName(type), type) {}

Tree::Tree(const std::string &name, const TREE_TYPE type) : m_name{name}, m_type{type}
{
    m_id = ++m_counter;
}

Tree::Tree(const Tree &tree)
{
    m_name = tree.getName();
    m_type = tree.getType();
    //m_id = tree.getId();
    m_id = ++m_counter;
}

void Tree::wind() const
{
    std::cout << "------------------------------------------------------" << std::endl;
    std::cout << std::left << std::setw(25) << "Tree name is : " << std::setw(25) << getName() << std::endl;
    std::cout << std::left << std::setw(25) << "Tree id is : " << std::setw(25) << getId() << std::endl;
    std::cout << "------------------------------------------------------" << std::endl;
}

std::string Tree::generateName(const TREE_TYPE type) const
{
    std::string res {};
    switch (type) {
    case TREE_TYPE::PINE:
    {
        res = m_pineTreeNames[0 + (rand() % 3)];
        break;
    }
    case TREE_TYPE::OAK:
    {
        res = m_oakTreeNames[0 + (rand() % 3)];
        break;
    }
    case TREE_TYPE::MAPLE:
    {
        res = m_mapleTreeNames[0 + (rand() % 3)];
        break;
    }
    case TREE_TYPE::BIRCH:
    {
        res = m_birchTreeNames[0 + (rand() % 3)];
        break;
    }
    case TREE_TYPE::ASPEN:
    {
        res = m_aspenTreeNames[0 + (rand() % 3)];
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
