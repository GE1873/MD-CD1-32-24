#include "coniferousforest.h"
#include <iostream>

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
