#ifndef FACTORIALCALCULATION_H
#define FACTORIALCALCULATION_H

#include <iomanip>
#include <iostream>

///
/// \brief Calculate factorial of number 5 for float and integer using function templates and recursion
///
class FactorialCalculation
{
public:
    FactorialCalculation();
    void calculateFactorial() const;

private:
    template<typename  T>
    T calculation(T) const;
};

#endif // FACTORIALCALCULATION_H
