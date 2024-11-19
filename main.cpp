#include <iomanip>
#include <iostream>
#include "factorialcalculation.h"
#include "systeminfo.h"

int main()
{
    FactorialCalculation fc;
    SystemInfo si;

    std::cout << "********************************************************************************" << std::endl;
    fc.calculateFactorial();
    std::cout << "********************************************************************************" << std::endl;
    si.getOSInfo();
    std::cout << "********************************************************************************" << std::endl;
    si.getCompilerInfo();
    std::cout << "********************************************************************************" << std::endl;

    return 0;
}
