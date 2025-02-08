#ifndef INVALIDLOGARGUMENT_H
#define INVALIDLOGARGUMENT_H

#include <string>

///
/// \brief The InvalidLogArgument class for user defined exception
///
class InvalidLogArgument
{
private:
    std::string _error;

public:
    InvalidLogArgument( const std::string& error );

    ///
    /// \brief Gets error message
    /// \return
    ///
    const char* getError() const noexcept;
};

#endif // INVALIDLOGARGUMENT_H
