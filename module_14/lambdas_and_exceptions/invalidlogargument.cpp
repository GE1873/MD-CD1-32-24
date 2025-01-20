#include "invalidlogargument.h"

InvalidLogArgument::InvalidLogArgument( const std::string& error ) : _error{ error }
{
}

const char* InvalidLogArgument::getError() const noexcept
{
    return _error.c_str();
}
