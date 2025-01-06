#include "treenamesgenerator.h"

std::string TreeNamesGenerator::generateName( const TreeType treeType )
{
    std::string res {};
    switch ( treeType ) {
    case TreeType::PINE:
    {
        res = _pineTreeNames[ 0 + (rand() % 3) ];
        break;
    }
    case TreeType::OAK:
    {
        res = _oakTreeNames[ 0 + (rand() % 3) ];
        break;
    }
    case TreeType::CEDAR:
    {
        res = _cedarTreeNames[ 0 + (rand() % 3) ];
        break;
    }
    case TreeType::BIRCH:
    {
        res = _birchTreeNames[ 0 + (rand() % 3) ];
        break;
    }
    default:
    {
        res = "undefined";
        break;
    }
    }
    return res;
}

std::string TreeNamesGenerator::getTypeName( const TreeType treeType )
{
    std::string res {};
    switch ( treeType ) {
    case TreeType::PINE:
    {
        res = "Pine";
        break;
    }
    case TreeType::OAK:
    {
        res = "Oak";
        break;
    }
    case TreeType::CEDAR:
    {
        res = "Cedar";
        break;
    }
    case TreeType::BIRCH:
    {
        res = "Birch";
        break;
    }
    default:
    {
        res = "undefined";
        break;
    }
    }
    return res;
}
