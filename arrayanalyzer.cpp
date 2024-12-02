#include "arrayanalyzer.h"

#include <iostream>
#include <memory>
#include <algorithm>

ArrayAnalyzer::ArrayAnalyzer()
{

}

void ArrayAnalyzer::createAndAnalizeArray()
{
    std::cout << "******************************************************" << std::endl;
    std::cout << "Array analyzing" << std::endl;
    std::cout << "******************************************************" << std::endl;
    size_t size {10};
    std::string str {};
    auto parr = std::make_unique<int[]>(size);
    std::cout << "Please, enter the first number : ";
    for(size_t i {}; i < size; ++i){
        std::getline (std::cin, str);
        try {
            parr[i] = std::stoi(str);
            if(i < size - 1) std::cout << "Please, enter the next number : ";
        } catch (std::invalid_argument &e) {
            std::cout<< "Invalid number! : " << str << std::endl;
            --i;
            std::cout << "Please, try to enter the number again : ";
        }
    }
    std::cout << "------------------------------------------------------" << std::endl;
    std::cout << "Array contents : ";
    for(size_t i {}; i < size; ++i){
        std::cout << parr[i] << " ";
    }
    std::cout << std::endl;
    int maxNum = *std::max_element(parr.get(), parr.get() + size);
    int minNum = *std::min_element(parr.get(), parr.get() + size);
    std::cout << "------------------------------------------------------" << std::endl;
    std::cout << "Maximum number in array is : " << maxNum << std::endl;
    std::cout << "Minimum number in array is : " << minNum << std::endl;
    std::cout << "------------------------------------------------------" << std::endl;
}
