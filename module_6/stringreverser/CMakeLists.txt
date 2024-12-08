cmake_minimum_required(VERSION 3.5)

project(module_6 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(module_6
    stringreverser.h
    stringreverser.cpp
    matrixcreator.h
    matrixcreator.cpp
    vectorsorter.h
    vectorsorter.cpp
    arrayanalyzer.h
    arrayanalyzer.cpp
    main.cpp
)

install(TARGETS module_6
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
