#include "calculator.h"
#include "invalidlogargument.h"
#include "invalidradusargument.h"

int main(){

    Calculator calculator;
    double res{};

    try {
        res = calculator.calculate(Calculator::MethodName::DIVISION, 5, 0);
        std::cout << res << std::endl;
    } catch (std::invalid_argument& e) {
        std::cerr << e.what() << std::endl;
    }

    try {
        res = calculator.calculate(Calculator::MethodName::SQUARE_ROOT, -5);
        std::cout << res << std::endl;
    } catch (std::domain_error& e) {
        std::cerr << e.what() << std::endl;
    }

    try {
        res = calculator.calculate(Calculator::MethodName::LOGARITHM, -5);
        std::cout << res << std::endl;
    } catch (InvalidLogArgument& e) {
        std::cerr << e.getError() << std::endl;
    }

    try {
        res = calculator.calculate(Calculator::MethodName::CIRCLE_AREA, -5);
        std::cout << res << std::endl;
    } catch (InvalidRadusArgument& e) {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}
