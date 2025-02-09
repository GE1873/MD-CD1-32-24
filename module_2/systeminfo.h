#ifndef SYSTEMINFO_H
#define SYSTEMINFO_H

#include <iostream>
#include <iomanip>

///
/// \brief Getting system information about OS and compiler
///        Tested on Astra Linux / Windows 11
///
class SystemInfo
{
public:
    SystemInfo();

    void getOSInfo() const;
    void getCompilerInfo() const;
};

#endif // SYSTEMINFO_H
