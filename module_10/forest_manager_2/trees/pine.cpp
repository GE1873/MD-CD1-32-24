#include "pine.h"
#include "treenamesgenerator.h"
#include <iomanip>
#include <iostream>

Pine::Pine()
{
    _treeType = TreeNamesGenerator::TreeType::PINE;
    _treeCategory = TreeNamesGenerator::TreeCategory::CONIFEROUS;
    _name = TreeNamesGenerator::generateName( _treeType );
    _id = ++_counter;
}

Pine::Pine( const Pine& pine )
{
    _treeType = pine.getTreeType();
    _treeCategory = pine.getTreeCategory();
    _name = pine.getName();
    _id = ++_counter;
}

void Pine::wind() const
{
    std::cout << "------------------------------------------------------" << std::endl;
    std::cout << std::left << std::setw( 25 ) << "Tree id is : " << std::setw( 25 ) << getId() << std::endl;
    std::cout << std::left << std::setw( 25 ) << "Tree type is : " << std::setw( 25 ) << TreeNamesGenerator::getTypeName( TreeNamesGenerator::TreeType::PINE ) << std::endl;
    std::cout << std::left << std::setw( 25 ) << "Tree name is : " << std::setw( 25 ) << getName() << std::endl;
}

size_t Pine::getNumOfTrees()
{
    return _counter;
}
