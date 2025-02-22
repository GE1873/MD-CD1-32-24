#include "groundexpressdelivery.h"
#include "groundexpresstariff.h"
#include <stdexcept>

GroundExpressDelivery::GroundExpressDelivery(std::unique_ptr<Tariff> tariff ) : _tariff{ std::move( tariff ) }
{
}

float GroundExpressDelivery::calculateCost( float weight, float distance ) const
{
    if( _tariff ) {
        return distance * static_cast<GroundExpressTariff*>( _tariff.get() )->getDistanceRate() * static_cast<GroundExpressTariff*>( _tariff.get() )->getTimeRate();
    }
    throw std::runtime_error( "Error : Delivery tariff is not set!" );
}
