#include "invalidlogargument.h"

InvalidLogArgument::InvalidLogArgument(const std::string& error) : _error(error)
{
}

const char* InvalidLogArgument::getError() const
{
    return _error.c_str();
}
