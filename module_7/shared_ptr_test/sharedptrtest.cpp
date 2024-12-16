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
    auto upArr {std::make_unique<int[]>(m_arrSize)};
    std::string str {};
    std::cout << "Please, enter the first number : ";
    for(size_t i {}; i < m_arrSize; ++i){
        std::getline (std::cin, str);
        try {
            upArr[i] = std::stoi(str);
            if(i < m_arrSize - 1) std::cout << "Please, enter the next number : ";
        }
        catch (const std::invalid_argument& e)
        {
            std::cerr<< "Error : Invalid number! : " << str << std::endl;
            --i;
            std::cout << "Please, try to enter the number again : ";
        }
        catch (const std::out_of_range& e)
        {
            std::cerr<< "Error : The number is out of range! : " << str << std::endl;
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
        for(size_t i {}; i < m_arrSize; ++i){
            std::cout << spArr[i] << " ";
        }
        std::cout << std::endl;
    } else {
        std::cerr << "Error : Array undefined!";
        std::cout << std::endl;
        exit(EXIT_FAILURE);
    }
}

void SharedPtrTest::sumArray(const std::weak_ptr<int[]>& num) const
{
    std::cout << "------------------------------------------------------" << std::endl;
    int sum{0};
    if(auto spArr = num.lock()){        
        for(size_t i {}; i < m_arrSize; ++i){            
            sum = sum + spArr[i];
        }
        std::cout << "The sum of the array is : " << sum << std::endl;
    } else {
        std::cerr << "Error : Array undefined!";
        std::cout << std::endl;
        exit(EXIT_FAILURE);
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
                std::cerr << "Error : The array size must be greater than zero!" << std::endl;
                std::cout << "Please, try to enter the size again : ";
            }
        }
        catch (const std::invalid_argument& e)
        {
            std::cerr<< "Error : Invalid number! : " << str << std::endl;
            std::cout << "Please, try to enter the number again : ";
        }
        catch (const std::out_of_range& e)
        {
            std::cerr<< "Error : The number is out of range! : " << str << std::endl;
            std::cout << "Please, try to enter the number again : ";
        }
    }
    std::cout << "------------------------------------------------------" << std::endl;
    return size;
}

void SharedPtrTest::sortArray(const std::weak_ptr<int[]> &num) const
{
    if(auto spArr = num.lock()){
        for (size_t i {}; i < m_arrSize - 1; ++i){
            for (size_t j {m_arrSize - 1}; j > i; --j){
                if (spArr[j - 1] > spArr[j]){
                    int temp = spArr[j - 1];
                    spArr[j - 1] = spArr[j];
                    spArr[j] = temp;
                }
            }
        }
    } else {
        std::cerr << "Error : Array undefined!";
        std::cout << std::endl;
        exit(EXIT_FAILURE);
    }
}

SharedPtrTest::MinMaxResult SharedPtrTest::getMinMaxNum(const std::weak_ptr<int[]> &num) const
{
    if(auto spArr = num.lock()){
        sortArray(num);
        return MinMaxResult{
            spArr[0],
            spArr[m_arrSize - 1]
        };
    } else {
        std::cerr << "Error : Array undefined!";
        std::cout << std::endl;
        exit(EXIT_FAILURE);
    }
}


