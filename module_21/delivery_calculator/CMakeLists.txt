cmake_minimum_required(VERSION 3.5)

project(delivery_calculator LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(delivery_calculator    
    main.cpp
    ideliverystrategy.h
    grounddelivery.h
    grounddelivery.cpp
    airdelivery.h
    airdelivery.cpp
    groundexpressdelivery.h
    groundexpressdelivery.cpp
    airexpressdelivery.h
    airexpressdelivery.cpp
    deliverystrategyfactory.h
    deliverystrategyfactory.cpp
    deliverycontext.h
    deliverycontext.cpp
    tariff.h
    tariff.cpp
    groundtariff.h
    groundtariff.cpp
    airtariff.h
    airtariff.cpp
    airexpresstariff.h
    airexpresstariff.cpp
    groundexpresstariff.h
    groundexpresstariff.cpp
)

install(TARGETS delivery_calculator
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
