#include "sharedptrtest.h"

#include <iostream>

SharedPtrTest::SharedPtrTest()
{
    
}

void SharedPtrTest::createArray()
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
    std::cout << "Array contents : ";
    for(size_t i {}; i < m_size; ++i){
        std::cout << m_parr[i] << " ";
    }
    std::cout << std::endl;
}

int SharedPtrTest::sumArray(const std::weak_ptr<int[]>& num)
{
    int sum{0};
    if(auto sp = num.lock()){
        for(size_t i {}; i < m_size; ++i){
            sum = sum + sp[i];
        }
    }
    return sum;
}

void SharedPtrTest::setArraySize()
{
    bool isSizeValid {};
    std::string str {};
    std::cout << "Please, enter the size of the array : ";
    while(!isSizeValid){
        std::getline (std::cin, str);
        try {
            m_size = std::stoi(str);
            isSizeValid = true;
        } catch (std::invalid_argument &e) {
            std::cout<< "Invalid number! : " << str << std::endl;
            std::cout << "Please, try to enter the size again : ";
        }
    }
    std::cout << "------------------------------------------------------" << std::endl;
}

std::shared_ptr<int[]> SharedPtrTest::getSharedPtr()
{
    return m_parr;
}

void SharedPtrTest::sortArray(const std::weak_ptr<int[]> &num)
{
    if(auto sp = num.lock()){
        for (size_t i {}; i < m_size - 1; ++i)        {
            for (size_t j = (m_size - 1); j > i; --j)
            {
                if (sp[j - 1] > sp[j])
                {
                    int temp = sp[j - 1];
                    sp[j - 1] = sp[j];
                    sp[j] = temp;
                }
            }
        }
    }
}

SharedPtrTest::MinMaxResult SharedPtrTest::getMinMaxNum(const std::weak_ptr<int[]> &num)
{
    MinMaxResult mmr;
    sortArray(num);

    if(auto sp = num.lock()){
        mmr.minNum = sp[0];
        mmr.maxNum = sp[m_size - 1];
    }

    return mmr;
}
