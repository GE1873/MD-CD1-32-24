#include "oak.h"
#include "treenamesgenerator.h"
#include <iomanip>
#include <iostream>

Oak::Oak()
{
    _treeType = TreeNamesGenerator::TreeType::OAK;
    _treeCategory = TreeNamesGenerator::TreeCategory::DECIDUOUS;
    _name = TreeNamesGenerator::generateName( _treeType );
    _id = ++_counter;
}

Oak::Oak( const Oak& oak )
{
    _treeType = oak.getTreeType();
    _treeCategory = oak.getTreeCategory();
    _name = oak.getName();
    _id = ++_counter;
}

void Oak::wind() const
{
    std::cout << "------------------------------------------------------" << std::endl;
    std::cout << std::left << std::setw( 25 ) << "Tree id is : " << std::setw( 25 ) << getId() << std::endl;
    std::cout << std::left << std::setw( 25 ) << "Tree type is : " << std::setw( 25 ) << TreeNamesGenerator::getTypeName( TreeNamesGenerator::TreeType::OAK ) << std::endl;
    std::cout << std::left << std::setw( 25 ) << "Tree name is : " << std::setw( 25 ) << getName() << std::endl;
}

size_t Oak::getNumOfTrees()
{
    return _counter;
}
