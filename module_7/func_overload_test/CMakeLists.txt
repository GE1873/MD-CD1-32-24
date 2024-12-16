cmake_minimum_required(VERSION 3.5)

project(func_overload_test LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(func_overload_test
    main.cpp
    funcoverloadtest.h
    funcoverloadtest.cpp
)

install(TARGETS func_overload_test
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
