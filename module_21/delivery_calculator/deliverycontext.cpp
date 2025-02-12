#include "deliverycontext.h"

void DeliveryContext::setStrategy( std::unique_ptr<IDeliveryStrategy> strategy )
{
    if ( strategy ) {
        _strategy = std::move( strategy );
    }
    else throw std::invalid_argument( "Error : Delivery strategy is not set!" );
}

float DeliveryContext::calculateCost( float weight, float distance ) const
{
    if ( _strategy ) {
        return _strategy->calculateCost( weight, distance );
    }
    throw std::runtime_error( "Error : Delivery strategy is not set!" );
}
