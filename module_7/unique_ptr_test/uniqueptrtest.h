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
    /// \brief Creates and populates an array
    ///
    void createArray();

    ///
    /// \brief Prints an array
    /// \param num
    ///
    void printArray(const std::unique_ptr<int[]>& num);

    ///
    /// \brief Gets an unique pointer to array
    /// \return unique_ptr<int[]>
    ///
    std::unique_ptr<int[]> getUniquePtr();

private:
    std::size_t m_size {10};
    std::unique_ptr<int[]> m_parr {std::make_unique<int[]>(m_size)};
};

#endif // UNIQUEPTRTEST_H
