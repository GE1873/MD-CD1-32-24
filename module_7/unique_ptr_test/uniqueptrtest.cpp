#include "uniqueptrtest.h"

#include <iostream>

UniquePtrTest::UniquePtrTest()
{
    
}

void UniquePtrTest::runTest()
{
    printArray(m_upArr);
}

std::unique_ptr<int[]> UniquePtrTest::getArray() const
{
    auto upArr {std::make_unique<int[]>(m_size)};
    std::string str {};
    std::cout << "Please, enter the first number : ";
    for(size_t i {}; i < m_size; ++i){
        std::getline (std::cin, str);
        try {
            upArr[i] = std::stoi(str);
            if(i < m_size - 1) std::cout << "Please, enter the next number : ";
        }
        catch (const std::invalid_argument& e)
        {
            std::cout << "Invalid number! : " << str << std::endl;
            --i;
            std::cout << "Please, try to enter the number again : ";
        }
        catch (const std::out_of_range& e)
        {
            std::cout << "The number is out of range! : " << str << std::endl;
            --i;
            std::cout << "Please, try to enter the number again : ";
        }
    }
    return upArr;
}

void UniquePtrTest::printArray(const std::unique_ptr<int[]>& num) const
{
    std::cout << "------------------------------------------------------" << std::endl;
    if(num){
        std::cout << "Array contents : ";
        for(size_t i {}; i < m_size; ++i){
            std::cout << num[i] << " ";
        }
        std::cout << std::endl;
    } else {
        std::cout << "Array undefined!";
        std::cout << std::endl;
        exit(0);
    }
}
