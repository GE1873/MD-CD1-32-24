#include "sharedptrtest.h"

#include <iostream>

SharedPtrTest::SharedPtrTest()
{
    
}

void SharedPtrTest::runTest()
{
    std::weak_ptr<int[]> wptr {m_pArr};
    populateArray();
    printArray(wptr);
    sumArray(wptr);
    const auto [minNum, maxNum] = getMinMaxNum(wptr);    
    std::cout << "------------------------------------------------------" << std::endl;
    std::cout << "Maximum number in array is : " << maxNum << std::endl;
    std::cout << "Minimum number in array is : " << minNum << std::endl;
    std::cout << "------------------------------------------------------" << std::endl;
}

void SharedPtrTest::populateArray() const
{
    std::string str {};
    std::cout << "Please, enter the first number : ";
    for(size_t i {}; i < m_size; ++i){
        std::getline (std::cin, str);
        try {
            m_pArr[i] = std::stoi(str);
            if(i < m_size - 1) std::cout << "Please, enter the next number : ";
        }
        catch (const std::invalid_argument& e)
        {
            std::cout<< "Invalid number! : " << str << std::endl;
            --i;
            std::cout << "Please, try to enter the number again : ";
        }
        catch (const std::out_of_range& e)
        {
            std::cout<< "The number is out of range! : " << str << std::endl;
            --i;
            std::cout << "Please, try to enter the number again : ";
        }
    }    
}

void SharedPtrTest::printArray(const std::weak_ptr<int[]> &num) const
{
    std::cout << "------------------------------------------------------" << std::endl;
    std::cout << "Array contents : ";
    if(auto sp = num.lock()){
        for(size_t i {}; i < m_size; ++i){
            std::cout << sp[i] << " ";
        }
    }
    std::cout << std::endl;
}

void SharedPtrTest::sumArray(const std::weak_ptr<int[]>& num) const
{
    int sum{0};
    if(auto sp = num.lock()){
        for(size_t i {}; i < m_size; ++i){
            sum = sum + sp[i];
        }
    }
    std::cout << "------------------------------------------------------" << std::endl;
    std::cout << "Sum of the array equal : " << sum << std::endl;    
}

int SharedPtrTest::getArraySize() const
{
    bool isSizeValid {};
    int size {};
    std::string str {};
    std::cout << "Please, enter the size of the array : ";
    while(!isSizeValid){
        std::getline (std::cin, str);
        try {
            size = std::stoi(str);
            if(size > 0){
                isSizeValid = true;
            } else {
                std::cout << "The array size must be greater than zero!" << std::endl;
                std::cout << "Please, try to enter the size again : ";
            }
        } catch (std::invalid_argument &e) {
            std::cout << "Invalid number! : " << str << std::endl;
            std::cout << "Please, try to enter the size again : ";
        }
    }
    std::cout << "------------------------------------------------------" << std::endl;
    return size;
}

void SharedPtrTest::sortArray(const std::weak_ptr<int[]> &num) const
{
    if(auto sp = num.lock()){
        for (size_t i {}; i < m_size - 1; ++i)        {
            for (size_t j {m_size - 1}; j > i; --j)
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

SharedPtrTest::MinMaxResult SharedPtrTest::getMinMaxNum(const std::weak_ptr<int[]> &num) const
{
    MinMaxResult mmr;
    sortArray(num);
    if(auto sp = num.lock()){
        mmr.minNum = sp[0];
        mmr.maxNum = sp[m_size - 1];
    }
    return mmr;
}
