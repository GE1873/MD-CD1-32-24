#include "factorialcalculation.h"
#include "settings.h"

FactorialCalculation::FactorialCalculation()
{

}

void FactorialCalculation::calculateFactorial() const
{
#ifdef FLOAT
    float f = calculation(5.0f);
    std::cout << std::left << std::setw(40) << "Factorial of number 5 in FLOAT:" << std::setw(40) << std::fixed << std::setprecision(1) << f <<std::endl;
#else
    int f = calculation(5);
    std::cout << std::left << std::setw(40) << "Factorial of number 5 in INTEGER:" << std::setw(40) << f <<std::endl;
#endif
}

template<typename T>
T FactorialCalculation::calculation(T num) const
{
    if (num == 0) return 1;
    else return num*calculation(num - 1);
}
