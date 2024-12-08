#include "../inc/stringreverser.h"

#include <algorithm>
#include <iostream>
#include <cstring>

StringReverser::StringReverser()
{

}

void StringReverser::reverseAndPrintEnteredString()
{
    std::cout << "******************************************************" << std::endl;
    std::cout << "Reverse the entered string" << std::endl;
    std::cout << "******************************************************" << std::endl;
    std::string s_str {};
    std::cout << "Please enter any string : ";
    std::getline (std::cin, s_str);
    size_t c_str_size = s_str.length() + 1;
    char c_str[c_str_size];
    memcpy(c_str, s_str.c_str(), c_str_size);
    reverseString(c_str);
    std::cout << "Reversed string is : " << c_str << std::endl;
}

void StringReverser::reverseString(char *str)
{
    char *strEnd = strchr(str, 0);
    std::reverse(str, strEnd);
}
