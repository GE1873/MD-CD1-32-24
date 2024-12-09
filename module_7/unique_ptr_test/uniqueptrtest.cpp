#include "uniqueptrtest.h"

#include <iostream>

UniquePtrTest::UniquePtrTest()
{
    
}

void UniquePtrTest::createArray()
{    
    std::string str {};
    std::cout << "Please, enter the first number : ";
    for(size_t i {}; i < m_size; ++i){
        std::getline (std::cin, str);
        try {
            m_parr[i] = std::stoi(str);
            if(i < m_size - 1) std::cout << "Please, enter the next number : ";
        } catch (std::invalid_argument &e) {
            std::cout<< "Invalid number! : " << str << std::endl;
            --i;
            std::cout << "Please, try to enter the number again : ";
        }
    }
    std::cout << "------------------------------------------------------" << std::endl;    
}

void UniquePtrTest::printArray(const std::unique_ptr<int[]>& num)
{
    std::cout << "Array contents : ";
    for(size_t i {}; i < m_size; ++i){
        std::cout << num[i] << " ";
    }
    std::cout << std::endl;
}

std::unique_ptr<int[]> UniquePtrTest::getUniquePtr() {
    return std::move(m_parr);
}
