cmake_minimum_required(VERSION 3.5)

project(shared_ptr_test LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(shared_ptr_test
    main.cpp
    sharedptrtest.h
    sharedptrtest.cpp
)

install(TARGETS shared_ptr_test
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
