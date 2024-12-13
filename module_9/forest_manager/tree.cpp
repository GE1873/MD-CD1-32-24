#include "tree.h"
#include <iomanip>
#include <iostream>

size_t Tree::m_counter{};
std::string Tree::pineTreeNames[3] = {"Pinus Jeffreyi", "Pinus Strobus", "Pinus Ponderosa"};
std::string Tree::oakTreeNames[3] = {"Black Oak", "Northern Red Oak", "Live Oak"};
std::string Tree::mapleTreeNames[3] = {"Red Maple", "Amur Maple", "Norway Maple"};
std::string Tree::birchTreeNames[3] = {"Silver Birch", "Dwarf Birch", "Himalayan Birch"};
std::string Tree::aspenTreeNames[3] = {"Golden Aspen", "European Aspen", "Trembling Aspen"};

Tree::Tree(const TREE_TYPE type) :
    Tree(generateName(type), type) {}

Tree::Tree(const std::string &name, const TREE_TYPE type) :
    m_name{name},
    m_type{type} {}

Tree::Tree(const Tree &tree) :
    m_name{tree.getName()},
    m_type{tree.getType()} {}

void Tree::wind() const
{
    std::cout << "------------------------------------------------------" << std::endl;
    std::cout << std::left << std::setw(25) << "Tree name is : " << std::setw(25) << m_name << std::endl;
    std::cout << std::left << std::setw(25) <<"Tree id is : " << std::setw(25) << m_id << std::endl;
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
