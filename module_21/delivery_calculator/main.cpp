#include "airexpresstariff.h"
#include "airtariff.h"
#include "deliverycontext.h"
#include "deliverystrategyfactory.h"
#include "groundexpresstariff.h"
#include "groundtariff.h"
#include <iomanip>
#include <iostream>

int main(){

    DeliveryStrategyFactory factory;
    DeliveryContext context;

    float weight = 50.0f;
    float distance = 500.0f;

    auto groundTariff = std::make_unique<GroundTariff>();
    groundTariff->setDistanceRate( 0.5f );
    try {
        factory.setTariff( DeliveryStrategyFactory::DeliveryTypes::Ground, std::move( groundTariff ) );
    } catch ( std::invalid_argument& e ) {
        std::cerr << e.what() << std::endl;
    }

    auto airTariff = std::make_unique<AirTariff>();
    airTariff->setDistanceRate( 0.3f );
    airTariff->setWeightRate( 2.5f );
    try {
        factory.setTariff( DeliveryStrategyFactory::DeliveryTypes::Air, std::move( airTariff ) );
    } catch ( std::invalid_argument& e ) {
        std::cerr << e.what() << std::endl;
    }

    auto groundExpressTariff = std::make_unique<GroundExpressTariff>();
    groundExpressTariff->setDistanceRate( 2.5f );
    groundExpressTariff->setTimeRate( 3.0f );
    try {
        factory.setTariff( DeliveryStrategyFactory::DeliveryTypes::Ground_Express, std::move( groundExpressTariff ) );
    } catch ( std::invalid_argument& e ) {
        std::cerr << e.what() << std::endl;
    }

    auto airExpressTariff = std::make_unique<AirExpressTariff>();
    airExpressTariff->setDistanceRate( 2.2f );
    airExpressTariff->setWeightRate( 3.0f );
    airExpressTariff->setTimeRate( 4.0f );
    try {
        factory.setTariff( DeliveryStrategyFactory::DeliveryTypes::Air_Express, std::move( airExpressTariff ) );
    } catch ( std::invalid_argument& e ) {
        std::cerr << e.what() << std::endl;
    }

    std::map<DeliveryStrategyFactory::DeliveryTypes, std::string> deliveryTypes =
        {
            {DeliveryStrategyFactory::DeliveryTypes::Ground, "Ground Delivery Cost : "},
            {DeliveryStrategyFactory::DeliveryTypes::Ground_Express, "Ground Express Delivery Cost : "},
            {DeliveryStrategyFactory::DeliveryTypes::Air, "Air Delivery Cost : "},
            {DeliveryStrategyFactory::DeliveryTypes::Air_Express, "Air Express Delivery Cost : "}
        };

    for ( const auto& [type, name] : deliveryTypes ) {
        std::cout << "------------------------------------------------------" << std::endl;
        try {
            context.setStrategy( factory.createStrategy( type ) );
            std::cout << std::left << std::setw( 45 ) << name << context.calculateCost( weight, distance ) << " $" << std::endl;
        } catch ( std::invalid_argument& e ) {
            std::cerr << e.what() << std::endl;
        } catch ( std::runtime_error& e ) {
            std::cerr << e.what() << std::endl;
        }
    }
    std::cout << "------------------------------------------------------" << std::endl;

    return 0;
}
