#include "airtariff.h"

AirTariff::AirTariff()
{
}

void AirTariff::setDistanceRate( float distanceRate ) { Tariff::setDistanceRate( distanceRate ); }

void AirTariff::setWeightRate( float weightRate ) { Tariff::setWeightRate( weightRate ); }

float AirTariff::getDistanceRate() const { return Tariff::getDistanceRate(); }

float AirTariff::getWeightRate() const { return Tariff::getWeightRate(); }
