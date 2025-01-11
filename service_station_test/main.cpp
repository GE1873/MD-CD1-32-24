#include "cargocar.h"
#include "passengercar.h"
#include "servicestation.h"
#include <iostream>
#include <memory>
#include <vector>

int main(){

    auto pcss = std::make_shared<ServiceStation<PassengerCar>>();
    auto pc1 = std::make_shared<PassengerCar>( "Audi A1" );
    auto pc2 = std::make_shared<PassengerCar>( "Audi A3" );
    auto pc3 = std::make_shared<PassengerCar>( "Audi A5" );
    auto pc4 = std::make_shared<PassengerCar>( "Audi A6" );
    auto pc5 = std::make_shared<PassengerCar>( "Audi A7" );
    auto pc6 = std::make_shared<PassengerCar>( "Audi A8" );
    if( pcss ){
        std::cout << "------------------------------------------------------" << std::endl;
        try{
            pcss->addCar( pc1 );
            pcss->addCar( pc2 );
            pcss->addCar( pc3 );
            pcss->addCar( pc4 );
            pcss->addCar( pc5 );
            pcss->addCar( pc6 );
        }
        catch ( const std::invalid_argument& e ){
            std::cerr << e.what() << std::endl;
        }
    } else{
        std::cerr << "Error : Service station class object is undefined!";
        std::cout << std::endl;
    }
    std::cout << "------------------------------------------------------" << std::endl;
    std::cout << "Passenger cars at the service station before repairs" << std::endl;
    std::cout << "------------------------------------------------------" << std::endl;
    pcss->displayServiceStation();
    try{
        pcss->repairAll();
    }
    catch ( const std::invalid_argument& e ){
        std::cerr << e.what() << std::endl;
    }
    std::cout << "------------------------------------------------------" << std::endl;
    std::cout << "Repaired passenger cars in the garage" << std::endl;
    std::cout << "------------------------------------------------------" << std::endl;
    pcss->displayGarage();

    auto ccss = std::make_shared<ServiceStation<CargoCar>>();
    auto cc1 = std::make_shared<CargoCar>( "Volvo FH16 Aero" );
    auto cc2 = std::make_shared<CargoCar>( "Volvo FMX" );
    auto cc3 = std::make_shared<CargoCar>( "Volvo FM" );
    auto cc4 = std::make_shared<CargoCar>( "Volvo FE" );
    auto cc5 = std::make_shared<CargoCar>( "Volvo FL" );
    auto cc6 = std::make_shared<CargoCar>( "Volvo FH16" );
    if( ccss ){
        std::cout << "------------------------------------------------------" << std::endl;
        try{
            ccss->addCar( cc1 );
            ccss->addCar( cc2 );
            ccss->addCar( cc3 );
            ccss->addCar( cc4 );
            ccss->addCar( cc5 );
            ccss->addCar( cc6 );
        }
        catch ( const std::invalid_argument& e ){
            std::cerr << e.what() << std::endl;
        }
    } else{
        std::cerr << "Error : Service station class object is undefined!";
        std::cout << std::endl;
    }
    std::cout << "------------------------------------------------------" << std::endl;
    std::cout << "Cargo cars at the service station before repairs" << std::endl;
    std::cout << "------------------------------------------------------" << std::endl;
    ccss->displayServiceStation();
    try{
        ccss->repairAll();
    }
    catch ( const std::invalid_argument& e ){
        std::cerr << e.what() << std::endl;
    }
    std::cout << "------------------------------------------------------" << std::endl;
    std::cout << "Repaired cargo cars in the garage" << std::endl;
    std::cout << "------------------------------------------------------" << std::endl;
    ccss->displayGarage();

    return 0;
}
