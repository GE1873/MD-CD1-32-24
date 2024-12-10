#ifndef SHAREDPTRTEST_H
#define SHAREDPTRTEST_H

#include <memory>

///
/// \brief Test class for learning smart shared pointer
///
class SharedPtrTest
{
public:
    SharedPtrTest();

    ///
    /// \brief Runs a shared smart pointer test
    ///
    void runTest();

private:    
    std::size_t m_size {static_cast<size_t>(getArraySize())};
    std::shared_ptr<int[]> m_spArr {std::move(getArray())};

    struct MinMaxResult {
        int minNum;
        int maxNum;
    };    

    int getArraySize() const;
    std::unique_ptr<int[]> getArray() const;
    void printArray(const std::weak_ptr<int[]>& num) const;
    void sumArray(const std::weak_ptr<int[]>& num) const;
    void sortArray(const std::weak_ptr<int[]>& num) const;
    MinMaxResult getMinMaxNum(const std::weak_ptr<int[]>& num) const;
};

#endif // SHAREDPTRTEST_H
