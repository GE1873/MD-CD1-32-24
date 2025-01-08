#include "oak.h"
#include "treenamesgenerator.h"
#include <iomanip>
#include <iostream>

Oak::Oak() : Tree( TreeNamesGenerator::generateName( TreeNamesGenerator::TreeType::OAK ),
           TreeNamesGenerator::TreeType::OAK,
           TreeNamesGenerator::TreeCategory::DECIDUOUS )
{    
    _id = ++_counter;
}

Oak::Oak( const Oak& oak ) : Tree( oak.getName(),
           oak.getTreeType(),
           oak.getTreeCategory() )
{    
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
