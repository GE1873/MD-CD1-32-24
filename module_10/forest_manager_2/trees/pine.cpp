#include "pine.h"
#include "treenamesgenerator.h"
#include <iomanip>
#include <iostream>

Pine::Pine() : Tree(TreeNamesGenerator::generateName( TreeNamesGenerator::TreeType::PINE ),
           TreeNamesGenerator::TreeType::PINE,
           TreeNamesGenerator::TreeCategory::CONIFEROUS )
{   
    _id = ++_counter;
}

Pine::Pine( const Pine& pine ) : Tree( pine.getName(),
           pine.getTreeType(),
           pine.getTreeCategory() )
{    
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
