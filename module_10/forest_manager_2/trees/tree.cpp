#include "tree.h"
#include <iomanip>
#include <iostream>

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
