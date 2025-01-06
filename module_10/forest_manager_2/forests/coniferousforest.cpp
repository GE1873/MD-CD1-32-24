#include "coniferousforest.h"
#include <iostream>

ConiferousForest::~ConiferousForest()
{
    if ( !_trees.empty() ){
        for (const Tree* tree : _trees)
        {
            if( tree ) delete tree;
        }
        _trees.clear();
    }
}

void ConiferousForest::growUp( Tree* tree )
{
    if( tree ){
        if( ( tree->getTreeCategory() == TreeNamesGenerator::TreeCategory::CONIFEROUS ) ){
            _trees.push_back( tree );
        }else{
            std::cerr << "Error: Wrong tree. Only conifers trees are allowed!" << std::endl;
        }
    }else throw std::invalid_argument( "Error : Tree class object is undefined!" );
}
