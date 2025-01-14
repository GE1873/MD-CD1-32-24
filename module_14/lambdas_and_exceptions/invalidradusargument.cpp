#include "invalidradusargument.h"

InvalidRadusArgument::InvalidRadusArgument(const std::string& error) : _error(error)
{
}

const char* InvalidRadusArgument::what() const noexcept
{
    return _error.c_str();
}
