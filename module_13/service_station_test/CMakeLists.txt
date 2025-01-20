cmake_minimum_required(VERSION 3.5)

project(service_station_test LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(service_station_test    
    main.cpp
    servicestation.h
    car.h
    car.cpp
    passengercar.h
    passengercar.cpp
    cargocar.h
    cargocar.cpp
)

install(TARGETS service_station_test
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
