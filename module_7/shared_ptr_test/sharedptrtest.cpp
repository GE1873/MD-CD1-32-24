#include "sharedptrtest.h"

#include <iostream>

SharedPtrTest::SharedPtrTest()
{
    
}

void SharedPtrTest::runTest()
{
    std::weak_ptr<int[]> wpArr {m_spArr};
    printArray(wpArr);
    sumArray(wpArr);
    const auto [minNum, maxNum] = getMinMaxNum(wpArr);
    std::cout << "------------------------------------------------------" << std::endl;
    std::cout << "Maximum number in array is : " << maxNum << std::endl;
    std::cout << "Minimum number in array is : " << minNum << std::endl;
    std::cout << "------------------------------------------------------" << std::endl;
}

std::unique_ptr<int[]> SharedPtrTest::getArray() const
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
    return upArr;
}

void SharedPtrTest::printArray(const std::weak_ptr<int[]> &num) const
{
    std::cout << "------------------------------------------------------" << std::endl;
    if(auto spArr = num.lock()){
        std::cout << "Array contents : ";
        for(size_t i {}; i < m_size; ++i){
            std::cout << spArr[i] << " ";
        }
        std::cout << std::endl;
    } else {
        std::cout << "Array undefined!";
        std::cout << std::endl;
        exit(0);
    }

}

void SharedPtrTest::sumArray(const std::weak_ptr<int[]>& num) const
{
    std::cout << "------------------------------------------------------" << std::endl;
    int sum{0};
    if(auto spArr = num.lock()){
        std::cout << "Sum of the array equal : " << sum << std::endl;
        for(size_t i {}; i < m_size; ++i){
            sum = sum + spArr[i];
        }
    } else {
        std::cout << "Array undefined!";
        std::cout << std::endl;
        exit(0);
    }
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
        }
        catch (const std::invalid_argument& e)
        {
            std::cout<< "Invalid number! : " << str << std::endl;
            std::cout << "Please, try to enter the number again : ";
        }
        catch (const std::out_of_range& e)
        {
            std::cout<< "The number is out of range! : " << str << std::endl;
            std::cout << "Please, try to enter the number again : ";
        }
    }
    std::cout << "------------------------------------------------------" << std::endl;
    return size;
}

void SharedPtrTest::sortArray(const std::weak_ptr<int[]> &num) const
{
    if(auto spArr = num.lock()){
        for (size_t i {}; i < m_size - 1; ++i)        {
            for (size_t j {m_size - 1}; j > i; --j)
            {
                if (spArr[j - 1] > spArr[j])
                {
                    int temp = spArr[j - 1];
                    spArr[j - 1] = spArr[j];
                    spArr[j] = temp;
                }
            }
        }
    } else {
        std::cout << "Array undefined!";
        std::cout << std::endl;
        exit(0);
    }
}

SharedPtrTest::MinMaxResult SharedPtrTest::getMinMaxNum(const std::weak_ptr<int[]> &num) const
{
    MinMaxResult mmr;
    sortArray(num);
    if(auto spArr = num.lock()){
        mmr.minNum = spArr[0];
        mmr.maxNum = spArr[m_size - 1];
    } else {
        std::cout << "Array undefined!";
        std::cout << std::endl;
        exit(0);
    }
    return mmr;
}
