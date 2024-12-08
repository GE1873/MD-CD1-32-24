cmake_minimum_required(VERSION 3.5)

project(arrayanalyzer LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(arrayanalyzer
    arrayanalyzer.h
    arrayanalyzer.cpp
    main.cpp
)

install(TARGETS arrayanalyzer
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
