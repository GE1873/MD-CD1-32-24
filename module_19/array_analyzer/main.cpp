#include "arrayanalyzer.h"
#include <iostream>

int main(){
    std::srand(std::time(0));

    ArrayAnalyzer a;

    a.addMethod( ArrayAnalyzer::MethodName::Sum );
    a.addMethod( ArrayAnalyzer::MethodName::Min );
    a.addMethod( ArrayAnalyzer::MethodName::Max );

    a.setArraySize(100);

    try {
        a.fillArray();
        a.printArray();
    } catch ( std::invalid_argument& e ) {
        std::cerr << e.what() << std::endl;
    }

    try {
        a.analyzeArray();
        a.printResults();
    } catch ( std::invalid_argument& e ) {
        std::cerr << e.what() << std::endl;
    }

    a.printResults();

    return 0;
}
