cmake_minimum_required(VERSION 3.5)

project(unique_ptr_test LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(unique_ptr_test    
    main.cpp
    uniqueptrtest.h
    uniqueptrtest.cpp
)

install(TARGETS unique_ptr_test
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
