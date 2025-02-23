#include "numberconverter.h"

#include <iostream>
#include <string>

NumberConverter::NumberConverter()
{

}

NumberConverter::OperationResult NumberConverter::checkNumber(int num)
{
    return OperationResult{
        (num % 2 == 0) && (num > 0) ? num << 2 : num >> 2,
        (num % 2 == 0) && (num > 0) ? NUMBER_STATE::EVEN_AND_POS : NUMBER_STATE::ODD_OR_NEG
    };

}

std::string NumberConverter::convertEnum(NUMBER_STATE numState)
{
    std::string res {};

    switch (numState) {
    case NUMBER_STATE::EVEN_AND_POS:
    {
        res = "EVEN_AND_POS";
        break;
    }
    case NUMBER_STATE::ODD_OR_NEG:
    {
        res = "ODD_OR_NEG";
        break;
    }
    case NUMBER_STATE::UNKNOWN:
    {
        res = "UNKNOWN";
        break;
    }
    default:
    {
        res = "UNKNOWN";
        break;
    }
    }
    return res;
}
