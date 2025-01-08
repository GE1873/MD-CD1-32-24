#include "cedar.h"
#include "treenamesgenerator.h"
#include <iomanip>
#include <iostream>

Cedar::Cedar() : Tree(TreeNamesGenerator::generateName( TreeNamesGenerator::TreeType::CEDAR ),
           TreeNamesGenerator::TreeType::CEDAR,
           TreeNamesGenerator::TreeCategory::CONIFEROUS )
{    
    _id = ++_counter;
}

Cedar::Cedar( const Cedar& cedar ) : Tree( cedar.getName(),
           cedar.getTreeType(),
           cedar.getTreeCategory() )
{   
    _id = ++_counter;
}

void Cedar::wind() const
{
    std::cout << "------------------------------------------------------" << std::endl;
    std::cout << std::left << std::setw( 25 ) << "Tree id is : " << std::setw( 25 ) << getId() << std::endl;
    std::cout << std::left << std::setw( 25 ) << "Tree type is : " << std::setw( 25 ) << TreeNamesGenerator::getTypeName( TreeNamesGenerator::TreeType::CEDAR ) << std::endl;
    std::cout << std::left << std::setw( 25 ) << "Tree name is : " << std::setw( 25 ) << getName() << std::endl;
}

size_t Cedar::getNumOfTrees()
{
    return _counter;
}
