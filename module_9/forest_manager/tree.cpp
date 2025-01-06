#include "tree.h"
#include <iomanip>
#include <iostream>

Tree::Tree(const TreeType treeType) : Tree{generateName(treeType), treeType} {}

Tree::Tree(const std::string& name, const TreeType treeType) : m_name{name}, m_treeType{treeType}
{
    m_id = ++m_counter;
}

Tree::Tree(const Tree& tree)
{
    m_name = tree.getName();
    m_treeType = tree.getTreeType();
    m_id = ++m_counter;
}

void Tree::wind() const
{
    std::cout << "------------------------------------------------------" << std::endl;
    std::cout << std::left << std::setw(25) << "Tree name is : " << std::setw(25) << getName() << std::endl;
    std::cout << std::left << std::setw(25) << "Tree id is : " << std::setw(25) << getId() << std::endl;
    std::cout << "------------------------------------------------------" << std::endl;
}

std::string Tree::generateName(const TreeType treeType) const
{
    std::string res {};
    switch (treeType) {
    case TreeType::PINE:
    {
        res = m_pineTreeNames[0 + (rand() % 3)];
        break;
    }
    case TreeType::OAK:
    {
        res = m_oakTreeNames[0 + (rand() % 3)];
        break;
    }
    case TreeType::MAPLE:
    {
        res = m_mapleTreeNames[0 + (rand() % 3)];
        break;
    }
    case TreeType::BIRCH:
    {
        res = m_birchTreeNames[0 + (rand() % 3)];
        break;
    }
    case TreeType::ASPEN:
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

Tree::TreeType Tree::getTreeType() const
{
    return m_treeType;
}

std::string Tree::getName() const
{
    return m_name;
}

size_t Tree::getId() const
{
    return m_id;
}
