cmake_minimum_required(VERSION 3.5)

project(total_commander_lite_version LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(total_commander_lite_version    
    main.cpp
)

install(TARGETS total_commander_lite_version
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
