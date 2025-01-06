#include "forest.h"
#include <memory>
#include <iostream>
#include <iomanip>
#include <vector>

bool Forest::isContainTreeType( const TreeNamesGenerator::TreeType type ) const
{
    for (const Tree* tree : _trees){
        if ( tree->getTreeType() == type ) return true;
    }
    return false;
}

void Forest::wind() const
{
    for (const Tree* tree : _trees){
        tree->wind();
    }    
}
