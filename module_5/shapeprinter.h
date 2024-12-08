#ifndef SHAPEPRINTER_H
#define SHAPEPRINTER_H

#include <string>

namespace Shapes {
///
/// \brief Checking and printing entered shape
///
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

    ///
    /// \brief Prints the entered shape
    /// \param shape
    ///
    void printShape(SHAPES shape);

    ///
    /// \brief Checks the entered string (shape)
    /// \param shape
    ///
    void checkShape(const std::string &shape);

    ///
    /// \brief Getter for shape
    /// \return
    ///
    SHAPES shape() const;

private:
    SHAPES m_shape {};

    ///
    /// \brief Sets the additional shape variable
    /// \param shape
    ///
    void setShape(const std::string_view &shape);
};
}

#endif // SHAPEPRINTER_H
