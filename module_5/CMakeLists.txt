cmake_minimum_required(VERSION 3.5)

project(module_6 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(module_6
#    main.cpp
#    factorialcalculation.h
#    factorialcalculation.cpp
#    settings.h
#    systeminfo.h
#    systeminfo.cpp
#    multiplicationtable.h
#    multiplicationtable.cpp
#    numbergame.h
#    numbergame.cpp
#    shapeprinter.h
#    shapeprinter.cpp
#    numberconverter.h
#    numberconverter.cpp
    module_6/stringreverser.h
    module_6/stringreverser.cpp
    module_6/matrixcreator.h
    module_6/matrixcreator.cpp
    module_6/vectorsorter.h
    module_6/vectorsorter.cpp
    module_6/arrayanalyzer.h
    module_6/arrayanalyzer.cpp
    module_6/main.cpp
)

install(TARGETS module_6
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
