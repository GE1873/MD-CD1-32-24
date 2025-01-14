#include "invalidlogargument.h"

InvalidLogArgument::InvalidLogArgument(std::string error) : m_error(error)
{
}

const char* InvalidLogArgument::getError()
{
    return m_error.c_str();
}
