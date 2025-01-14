#include "invalidradusargument.h"

InvalidRadusArgument::InvalidRadusArgument(std::string error) : m_error(error)
{
}

const char *InvalidRadusArgument::what() const noexcept
{
    return m_error.c_str();
}
