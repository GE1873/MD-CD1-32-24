cmake_minimum_required(VERSION 3.5)

project(MD-CD1-32-24 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(MD-CD1-32-24
    main.cpp
    factorialcalculation.h
    factorialcalculation.cpp
    settings.h
    systeminfo.h
    systeminfo.cpp  
    multiplicationtable.h
    multiplicationtable.cpp
    numbergame.h
    numbergame.cpp
    shapeprinter.h
    shapeprinter.cpp
    numberconverter.h
    numberconverter.cpp
    stringreverser.h
    stringreverser.cpp
    matrixcreator.h
    matrixcreator.cpp
    vectorsorter.h
    vectorsorter.cpp
    arrayanalyzer.h
    arrayanalyzer.cpp
)

install(TARGETS MD-CD1-32-24
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
