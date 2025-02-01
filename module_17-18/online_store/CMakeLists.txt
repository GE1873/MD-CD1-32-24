cmake_minimum_required(VERSION 3.5)

project(online_store LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(online_store
    main.cpp
    order.h
    order.cpp
    manager.h
    manager.cpp
)

install(TARGETS online_store
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
