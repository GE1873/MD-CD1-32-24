cmake_minimum_required(VERSION 3.5)

project(file_manager LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(file_manager
    main.cpp
    filemanager.h
    filemanager.cpp
)

install(TARGETS file_manager
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
