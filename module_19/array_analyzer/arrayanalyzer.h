#ifndef ARRAYANALYZER_H
#define ARRAYANALYZER_H

#include <functional>
#include <future>
#include <mutex>
#include <map>

///
/// \brief The ArrayAnalyzer class for analyzing arrays
///
class ArrayAnalyzer
{
public:
    enum class MethodName {
        Unknown,
        Sum,
        Min,
        Max
    };

public:
    ArrayAnalyzer() = default;

    ///
    /// \brief Adds methods for analyzing arrays
    /// \param methodName
    ///
    void addMethod( MethodName methodName );

    ///
    /// \brief Sets the size of the array
    /// \param size
    ///
    void setArraySize( size_t size );

    ///
    /// \brief Fills an array with random numbers
    ///
    void fillArray();

    ///
    /// \brief Prints the contents of an array
    ///
    void printArray() const;

    ///
    /// \brief Performs array analysis according to the selected methods
    ///
    void analyzeArray();

    ///
    /// \brief Prints the analysis results
    ///
    void printResults();

private:
    std::string getMethodName( MethodName methodName ) const;
    std::function<void( std::promise<int> )> getMethod( MethodName methodName );

    std::map<MethodName, std::function<void( std::promise<int> )>> _methods{};
    std::vector<std::thread> _threads{};
    std::map<MethodName, std::future<int>> _futures{};
    size_t _size{};
    std::vector<int> _data{};
};

#endif // ARRAYANALYZER_H
