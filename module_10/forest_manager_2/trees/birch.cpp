#include "birch.h"
#include "treenamesgenerator.h"
#include <iomanip>
#include <iostream>

Birch::Birch() : Tree(TreeNamesGenerator::generateName( TreeNamesGenerator::TreeType::BIRCH ),
           TreeNamesGenerator::TreeType::BIRCH,
           TreeNamesGenerator::TreeCategory::DECIDUOUS )
{
    _id = ++_counter;
}

Birch::Birch( const Birch& birch ) : Tree( birch.getName(),
           birch.getTreeType(),
           birch.getTreeCategory() )
{    
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
