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

void Shapes::ShapePrinter::checkShape(std::string shape)
{
    shape == "circle" || shape == "square" || shape == "triangle" ? setShape(shape) : setShape("unknown");
}

void Shapes::ShapePrinter::setShape(std::string shape)
{
    if(shape == "circle") {
        m_shape = SHAPES::CIRCLE;
    }
    else if(shape == "square") {
        m_shape = SHAPES::SQUARE;
    }
    else if(shape == "triangle") {
        m_shape = SHAPES::TRIANGLE;
    }
    else if(shape == "unknown") {
        m_shape = SHAPES::UNKNOWN;
    }
}

Shapes::ShapePrinter::SHAPES Shapes::ShapePrinter::shape() const
{
    return m_shape;
}


