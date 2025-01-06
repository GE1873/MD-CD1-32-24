cmake_minimum_required(VERSION 3.5)

project(forest_manager_2 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(forest_manager_2    
    main.cpp
    trees/tree.h
    trees/tree.cpp
    trees/treenamesgenerator.h
    trees/treenamesgenerator.cpp
    trees/pine.h
    trees/pine.cpp
    trees/cedar.h
    trees/cedar.cpp
    trees/oak.h
    trees/oak.cpp
    trees/birch.h
    trees/birch.cpp
    forests/forest.h
    forests/forest.cpp
    forests/coniferousforest.h
    forests/coniferousforest.cpp
    forests/deciduousforest.h
    forests/deciduousforest.cpp
)

install(TARGETS forest_manager_2
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
