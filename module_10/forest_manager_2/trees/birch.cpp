#include "birch.h"
#include "treenamesgenerator.h"
#include <iomanip>
#include <iostream>

Birch::Birch()
{
    _treeType = TreeNamesGenerator::TreeType::BIRCH;
    _treeCategory = TreeNamesGenerator::TreeCategory::DECIDUOUS;
    _name = TreeNamesGenerator::generateName( _treeType );
    _id = ++_counter;
}

Birch::Birch( const Birch& birch )
{
    _treeType = birch.getTreeType();
    _treeCategory = birch.getTreeCategory();
    _name = birch.getName();
    _id = ++_counter;
}

void Birch::wind() const
{
    std::cout << "------------------------------------------------------" << std::endl;
    std::cout << std::left << std::setw( 25 ) << "Tree id is : " << std::setw( 25 ) << getId() << std::endl;
    std::cout << std::left << std::setw( 25 ) << "Tree type is : " << std::setw( 25 ) << TreeNamesGenerator::getTypeName( TreeNamesGenerator::TreeType::BIRCH ) << std::endl;
    std::cout << std::left << std::setw( 25 ) << "Tree name is : " << std::setw( 25 ) << getName() << std::endl;
}

size_t Birch::getNumOfTrees()
{
    return _counter;
}
