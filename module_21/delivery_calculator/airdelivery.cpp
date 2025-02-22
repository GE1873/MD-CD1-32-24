#include "airdelivery.h"
#include "airtariff.h"
#include <stdexcept>

AirDelivery::AirDelivery(std::unique_ptr<Tariff> tariff ) : _tariff{ std::move( tariff ) }
{
}

float AirDelivery::calculateCost( float weight, float distance ) const
{
    if( _tariff ) {
        return weight * static_cast<AirTariff*>( _tariff.get() )->getWeightRate() + distance * static_cast<AirTariff*>( _tariff.get() )->getDistanceRate();
    }
    throw std::runtime_error( "Error : Delivery tariff is not set!" );
}
