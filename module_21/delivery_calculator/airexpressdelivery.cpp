#include "airexpressdelivery.h"
#include "airexpresstariff.h"
#include <stdexcept>

AirExpressDelivery::AirExpressDelivery(std::unique_ptr<Tariff> tariff ) : _tariff{ std::move( tariff ) }
{
}

float AirExpressDelivery::calculateCost( float weight, float distance ) const
{
    if( _tariff ) {
        return ( weight * static_cast<AirExpressTariff*>( _tariff.get() )->getWeightRate() + distance * static_cast<AirExpressTariff*>( _tariff.get() )->getDistanceRate() ) * static_cast<AirExpressTariff*>( _tariff.get() )->getTimeRate();
    }
    throw std::runtime_error( "Error : Delivery tariff is not set!" );
}
