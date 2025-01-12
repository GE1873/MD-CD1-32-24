cmake_minimum_required(VERSION 3.5)

project(lambdas_and_exceptions LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(lambdas_and_exceptions    
    main.cpp    
)

install(TARGETS lambdas_and_exceptions
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
