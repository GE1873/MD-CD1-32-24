#include "funcoverloadtest.h"

#include <ctime>
#include <iostream>
#include <typeinfo>
#include <cxxabi.h>

FuncOverloadTest::FuncOverloadTest()
{

}

void FuncOverloadTest::runTest()
{
    std::srand(std::time(0));

    /* Testing a function with argument type: int */
    print(-100 + (rand() % 201));

    /* Testing a function with argument type: float */
    print(-100.0f + static_cast<float>(rand())/(static_cast<float>(RAND_MAX/(200.0f))));

    /* Testing a function with argument type: std::string */
    std::string str = "Hello, World!";
    print(str);

    /* Testing a function with argument type: char* (array) */
    char* carr = new char[m_arrSize];
    for(size_t i{}; i < m_arrSize; ++i){
        *(carr + i) = 'a' + rand() % 26;
    }
    print(carr);
    delete[] carr;
    carr = nullptr;

    /* Testing a function with argument type: int* (array) */
    int* iarr = new int[m_arrSize];
    for(size_t i{}; i < m_arrSize; ++i){
        *(iarr + i) = -100 + (rand() % 201);
    }
    print(iarr);
    delete[] iarr;
    iarr = nullptr;

    /* Testing a function with argument type: std::vector<int> */
    std::vector<int> v {};
    for (size_t i {}; i < m_arrSize; ++i) {
        v.push_back(-100 + (rand() % 201));
    }
    print(v);

    /* Testing a function with argument type: std::unique_ptr<double> */
    auto uptr {std::make_unique<double>(100.0 + static_cast<double>(rand())/(static_cast<double>(RAND_MAX/(200.0))))};
    print(std::move(uptr));

    /* Testing a function with argument type: std::shared_ptr<int> */
    auto sptr {std::make_shared<int>(-100 + (rand() % 201))};
    print(sptr);
}

void FuncOverloadTest::print(int value)
{
    std::cout << "------------------------------------------------------" << std::endl;
    std::cout << "Testing a function with argument type: int" << std::endl;
#if defined (__GNUC__)
    std::cout << "Variable type : " << abi::__cxa_demangle(typeid(value).name(), nullptr, nullptr, nullptr) << std::endl;
#else
    std::cout << "Variable type : " << typeid(value).name() << std::endl;
#endif
    std::cout << "Variable value : " << value << std::endl;
}

void FuncOverloadTest::print(float value)
{
    std::cout << "------------------------------------------------------" << std::endl;
    std::cout << "Testing a function with argument type: float" << std::endl;
#if defined (__GNUC__)
    std::cout << "Variable type : " << abi::__cxa_demangle(typeid(value).name(), nullptr, nullptr, nullptr) << std::endl;
#else
    std::cout << "Variable type : " << typeid(value).name() << std::endl;
#endif
    std::cout << "Variable value : " << value << std::endl;
}

void FuncOverloadTest::print(std::string value)
{
    std::cout << "------------------------------------------------------" << std::endl;
    std::cout << "Testing a function with argument type: std::string" << std::endl;
#if defined (__GNUC__)
    std::cout << "Variable type : " << abi::__cxa_demangle(typeid(value).name(), nullptr, nullptr, nullptr) << std::endl;
#else
    std::cout << "Variable type : " << typeid(value).name() << std::endl;
#endif
    std::cout << "Variable value : " << value << std::endl;
}

void FuncOverloadTest::print(char* value)
{
    std::cout << "------------------------------------------------------" << std::endl;
    std::cout << "Testing a function with argument type: char* (array)" << std::endl;
#if defined (__GNUC__)
    std::cout << "Variable type : " << abi::__cxa_demangle(typeid(value).name(), nullptr, nullptr, nullptr) << std::endl;
#else
    std::cout << "Variable type : " << typeid(value).name() << std::endl;
#endif
    std::cout << "Char array contents : ";
    for(size_t i {}; i < m_arrSize; ++i){
        std::cout << *(value + i) << " ";
    }
    std::cout << std::endl;
}

void FuncOverloadTest::print(int* value)
{
    std::cout << "------------------------------------------------------" << std::endl;
    std::cout << "Testing a function with argument type: int* (array)" << std::endl;
#if defined (__GNUC__)
    std::cout << "Variable type : " << abi::__cxa_demangle(typeid(value).name(), nullptr, nullptr, nullptr) << std::endl;
#else
    std::cout << "Variable type : " << typeid(value).name() << std::endl;
#endif
    std::cout << "Integer array contents : ";
    for(size_t i {}; i < m_arrSize; ++i){
        std::cout << *(value + i) << " ";
    }
    std::cout << std::endl;
}

void FuncOverloadTest::print(std::vector<int> value)
{
    std::cout << "------------------------------------------------------" << std::endl;
    std::cout << "Testing a function with argument type: std::vector<int>" << std::endl;
#if defined (__GNUC__)
    std::cout << "Variable type : " << abi::__cxa_demangle(typeid(value).name(), nullptr, nullptr, nullptr) << std::endl;
#else
    std::cout << "Variable type : " << typeid(value).name() << std::endl;
#endif
    std::cout << "Vector contents : ";
    for (const auto& v : value) {
        std::cout << v << " ";
    }
    std::cout << std::endl;
}

void FuncOverloadTest::print(std::unique_ptr<double> value)
{
    std::cout << "------------------------------------------------------" << std::endl;
    std::cout << "Testing a function with argument type: std::unique_ptr<double>" << std::endl;
#if defined (__GNUC__)
    std::cout << "Variable type : " << abi::__cxa_demangle(typeid(value).name(), nullptr, nullptr, nullptr) << std::endl;
#else
    std::cout << "Variable type : " << typeid(value).name() << std::endl;
#endif
    std::cout << "Variable value : " << *value << std::endl;
}

void FuncOverloadTest::print(std::shared_ptr<int> value)
{
    std::cout << "------------------------------------------------------" << std::endl;
    std::cout << "Testing a function with argument type: std::shared_ptr<int>" << std::endl;
#if defined (__GNUC__)
    std::cout << "Variable type : " << abi::__cxa_demangle(typeid(value).name(), nullptr, nullptr, nullptr) << std::endl;
#else
    std::cout << "Variable type : " << typeid(value).name() << std::endl;
#endif
    std::cout << "Variable value : " << *value << std::endl;
}
