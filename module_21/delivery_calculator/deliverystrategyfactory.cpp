#include "deliverystrategyfactory.h"
#include "airdelivery.h"
#include "airexpressdelivery.h"
#include "grounddelivery.h"
#include "groundexpressdelivery.h"

void DeliveryStrategyFactory::setTariff( DeliveryTypes type, std::unique_ptr<Tariff> tariff )
{
    if ( tariff ) {
        _tariffs[type] = std::move( tariff );
    }
    else throw std::invalid_argument( "Error : Delivery tariff is not set!" );

}

std::unique_ptr<IDeliveryStrategy> DeliveryStrategyFactory::createStrategy( DeliveryTypes type )
{
    if ( _tariffs.find( type ) == _tariffs.end() ) {
        throw std::runtime_error( "Error : Delivery tariff is not found!" );
    }

    switch ( type ) {
    case DeliveryTypes::Ground:
        return std::make_unique<GroundDelivery>( std::move( _tariffs[type] ) );
    case DeliveryTypes::Ground_Express:
        return std::make_unique<GroundExpressDelivery>( std::move( _tariffs[type] ) );
    case DeliveryTypes::Air:
        return std::make_unique<AirDelivery>( std::move( _tariffs[type] ) );
    case DeliveryTypes::Air_Express:
        return std::make_unique<AirExpressDelivery>( std::move( _tariffs[type] ) );
    default:
        break;
    }

    throw std::invalid_argument( "Error : Unknown delivery type!" );
}

