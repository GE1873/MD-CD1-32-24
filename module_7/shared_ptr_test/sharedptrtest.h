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
    /// \brief Creates and populates an array
    ///
    void createArray();

    ///
    /// \brief Adds up the contents of the array
    /// \param num
    /// \return int
    ///
    int sumArray(const std::weak_ptr<int[]>& num);

    ///
    /// \brief Sets size of an array
    /// \param newSize
    ///
    void setArraySize();

    ///
    /// \brief Gets an shared pointer to array
    /// \return unique_ptr<int[]>
    ///
    std::shared_ptr<int[]> getSharedPtr();    

private:    
    void sortArray(const std::weak_ptr<int[]>& num);

    std::size_t m_size {0};
    std::shared_ptr<int[]> m_parr {new int[m_size]};

    struct MinMaxResult {
        int minNum;
        int maxNum;
    };

public:
    ///
    /// \brief Gets minimun and maximum number from array
    /// \param num
    /// \return MinMaxResult
    ///
    MinMaxResult getMinMaxNum(const std::weak_ptr<int[]>& num);

};

#endif // SHAREDPTRTEST_H
