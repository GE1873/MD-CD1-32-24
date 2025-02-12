#include "grounddelivery.h"
#include "groundtariff.h"
#include <stdexcept>

GroundDelivery::GroundDelivery( std::unique_ptr<Tariff> tariff ) : _tariff{ std::move( tariff) }
{
}

float GroundDelivery::calculateCost( float weight, float distance ) const
{
    if( _tariff ) {
        return distance * static_cast<GroundTariff*>( _tariff.get() )->getDistanceRate();
    }
    throw std::runtime_error( "Error : Delivery tariff is not set!" );
}
