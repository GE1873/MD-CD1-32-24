#include "tree.h"
#include <iomanip>
#include <iostream>

Tree::Tree(std::string name, TreeNamesGenerator::TreeType treeType, TreeNamesGenerator::TreeCategory treeCategory) :
    _name{ name }, _treeType{ treeType }, _treeCategory{ treeCategory }
{
}

std::string Tree::getName() const
{
    return _name;
}

size_t Tree::getId() const
{
    return _id;
}

TreeNamesGenerator::TreeType Tree::getTreeType() const
{
    return _treeType;
}

TreeNamesGenerator::TreeCategory Tree::getTreeCategory() const
{
    return _treeCategory;
}

