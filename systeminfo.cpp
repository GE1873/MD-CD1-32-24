#include "systeminfo.h"

#if defined(__linux__)
#include <sys/utsname.h>
#elif defined(_WIN32)
#include <windows.h>
#endif

SystemInfo::SystemInfo()
{

}

void SystemInfo::getOSInfo () const
{
    std::string osName = "";
    std::string osVersion = "";
    std::string osType = "";

#if defined(__linux__)
    osName = "Linux";
    struct utsname utsbuf;
    int uname(struct utsname *utsbuf);
    if(uname(&utsbuf) != -1) {
        osVersion = std::string(utsbuf.release);
        osType = std::string(utsbuf.machine);
    }
#elif defined(_WIN32)
    osName = "Windows";
    int buildNumber = 0;

    ///
    /// \brief using https://learn.microsoft.com/en-us/answers/questions/595325/need-to-get-real-os-version
    ///
    HMODULE hDll = LoadLibrary(TEXT("Ntdll.dll"));
    typedef NTSTATUS(CALLBACK* RTLGETVERSION) (PRTL_OSVERSIONINFOW lpVersionInformation);
    RTLGETVERSION pRtlGetVersion;
    pRtlGetVersion = (RTLGETVERSION)GetProcAddress(hDll, "RtlGetVersion");
    if (pRtlGetVersion)
    {
        RTL_OSVERSIONINFOW ovi = { 0 };
        ovi.dwOSVersionInfoSize = sizeof(ovi);
        NTSTATUS ntStatus = pRtlGetVersion(&ovi);
        if (ntStatus == 0)
        {
            buildNumber = ovi.dwBuildNumber;
            if(ovi.dwMajorVersion == 10){
                if(buildNumber >= 22000) {
                    osVersion = std::to_string(11);
                } else osVersion = std::to_string(10);
            }
        }
    }

    osType =
#if defined(_WIN64)
        "x86_x64";
#else
        "x86";
#endif
#else
    osName = "undefined";
    osVersion = "undefined";
    osType = "undefined";
#endif

    std::cout << std::left << std::setw(25) << "OS name : " << std::setw(25) << osName << std::endl;
    std::cout << std::setw(25) << "OS version : " << std::setw(25) << osVersion << std::endl;
    std::cout << std::setw(25) << "OS type : " << std::setw(25) << osType << std::endl;
}

void SystemInfo::getCompilerInfo() const
{
    std::string compilerName = "";
    std::string compilerVersion = "";

#if defined (__clang__)
    compilerName = "clang++";
    compilerVersion = std::string(__VERSION__);
#elif defined (_MSC_VER)
    compilerName = "msvc";
    compilerVersion = std::string(_MSC_FULL_VER);
#elif defined (__GNUC__)
    compilerName = "g++";
    compilerVersion = std::string(__VERSION__);
#else
    compilerName = "undefined";
    compilerVersion = "undefined";
#endif

    std::cout << std::left << std::setw(25) << "Compiler name : " <<  std::setw(25) << compilerName << std::endl;
    std::cout << std::setw(25) << "Compiler version : " << std::setw(25) << compilerVersion << std::endl;
    std::cout << std::setw(25) << "C++ language version : " << std::setw(25) << __cplusplus << std::endl;    
}
