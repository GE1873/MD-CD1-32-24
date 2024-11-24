#include "shapeprinter.h"
#include <iomanip>
#include <iostream>
#include <string>

Shapes::ShapePrinter::ShapePrinter()
{

}

void Shapes::ShapePrinter::printShape(SHAPES shape)
{
    std::string _shape {};

    switch (shape) {
    case SHAPES::CIRCLE:
    {
        _shape = "circle";
        break;
    }
    case SHAPES::SQUARE:
    {
        _shape = "square";
        break;
    }
    case SHAPES::TRIANGLE:
    {
        _shape = "triangle";
        break;
    }
    default:
    {
        _shape = "unknown";
        break;
    }
    }
    std::cout << std::left << std::setw(15)  << "Current shape is : " << _shape << std::endl;
}
