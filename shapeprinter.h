#ifndef SHAPEPRINTER_H
#define SHAPEPRINTER_H

namespace Shapes {

class ShapePrinter
{
public:
    ShapePrinter();

    enum class SHAPES{
        UNKNOWN = -1,
        CIRCLE = 100,
        SQUARE = 200,
        TRIANGLE = 300
    };

    void printShape(SHAPES shape);
};

}



#endif // SHAPEPRINTER_H
