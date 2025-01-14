#ifndef INVALIDRADUSARGUMENT_H
#define INVALIDRADUSARGUMENT_H

#include <exception>
#include <string>

///
/// \brief The InvalidRadusArgument class for a custom exception inherited from std::exception
///
class InvalidRadusArgument: public std::exception
{
private:
    std::string _error;

public:
    InvalidRadusArgument(const std::string& error);

    ///
    /// \brief Gets error message
    /// \return
    ///
    const char* what() const noexcept override;
};

#endif // INVALIDRADUSARGUMENT_H
