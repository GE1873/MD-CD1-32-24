#ifndef INVALIDLOGARGUMENT_H
#define INVALIDLOGARGUMENT_H

#include <string>

///
/// \brief The InvalidLogArgument class for user defined exception
///
class InvalidLogArgument
{
private:
    std::string m_error;

public:
    InvalidLogArgument(std::string error);

    ///
    /// \brief Gets error message
    /// \return
    ///
    const char* getError();
};

#endif // INVALIDLOGARGUMENT_H
