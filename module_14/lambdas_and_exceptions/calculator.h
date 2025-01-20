#ifndef CALCULATOR_H
#define CALCULATOR_H

#include <functional>
#include <iostream>
#include <cmath>

///
/// \brief The Calculator class
///
class Calculator {
public:
    enum class MethodName {
        UNKNOWN = -1,
        DIVISION,
        SQUARE_ROOT,
        LOGARITHM,
        CIRCLE_AREA
    };

public:
    Calculator();

    ///
    /// \brief Calculates depending on the specified type of operation
    /// \param method
    /// \param value1
    /// \param value2
    /// \return
    ///
    double calculate( const MethodName method, double value1, double value2 = 0 );

private:
    std::function<double( double, double )> getMethod( const MethodName method ) const;

    std::vector<std::function<double( double, double )>> _methods{};
};

#endif // CALCULATOR_H
