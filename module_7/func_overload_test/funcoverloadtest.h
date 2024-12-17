#ifndef FUNCOVERLOADTEST_H
#define FUNCOVERLOADTEST_H

#include <memory>
#include <string>
#include <vector>

///
/// \brief Test class for learning function overload
///
class FuncOverloadTest
{
public:
    FuncOverloadTest();

    ///
    /// \brief Runs a function overload test
    ///
    void runTest();

private:
    size_t m_arrSize {10};

    void print(int value);
    void print(float value);
    void print(std::string value);
    void print(char* value);
    void print(int* value);
    void print(std::vector<int> value);
    void print(std::unique_ptr<double> value);
    void print(std::shared_ptr<int> value);
};

#endif // FUNCOVERLOADTEST_H
