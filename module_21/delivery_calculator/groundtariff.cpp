#include "groundtariff.h"

GroundTariff::GroundTariff()
{
}

void GroundTariff::setDistanceRate( float distanceRate ) { Tariff::setDistanceRate( distanceRate ); }

float GroundTariff::getDistanceRate() const { return Tariff::getDistanceRate(); }
