#include "deciduousforest.h"
#include <iostream>

DeciduousForest::~DeciduousForest()
{
    if ( !_trees.empty() ){
        for (const Tree* tree : _trees)
        {
            if( tree ) delete tree;
        }
        _trees.clear();
    }
}

void DeciduousForest::growUp( Tree* tree )
{
    if( tree ){
        if( ( tree->getTreeCategory() == TreeNamesGenerator::TreeCategory::DECIDUOUS ) ){
            _trees.push_back( tree );
        }else{
            std::cerr << "Error: Wrong tree. Only deciduous trees are allowed!" << std::endl;
        }
    }else throw std::invalid_argument( "Error : Tree class object is undefined!" );
}
