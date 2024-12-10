#ifndef UNIQUEPTRTEST_H
#define UNIQUEPTRTEST_H

#include <memory>

///
/// \brief Test class for learning smart unique pointer
///
class UniquePtrTest
{
public:
    UniquePtrTest();

    ///
    /// \brief Runs a unique smart pointer test
    ///
    void runTest();

private:
    std::size_t m_size {10};
    std::unique_ptr<int[]> m_pArr {std::make_unique<int[]>(m_size)};

    void populateArray() const;
    void printArray(const std::unique_ptr<int[]>& num) const;
};

#endif // UNIQUEPTRTEST_H
