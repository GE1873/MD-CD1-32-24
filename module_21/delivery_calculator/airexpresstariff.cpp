#include "airexpresstariff.h"

AirExpressTariff::AirExpressTariff()
{
}

void AirExpressTariff::setDistanceRate( float distanceRate ) { Tariff::setDistanceRate( distanceRate ); }

void AirExpressTariff::setWeightRate( float weightRate ) { Tariff::setWeightRate( weightRate ); }

void AirExpressTariff::setTimeRate( float timeRate ) { Tariff::setTimeRate( timeRate ); }

float AirExpressTariff::getDistanceRate() const { return Tariff::getDistanceRate(); }

float AirExpressTariff::getWeightRate() const { return Tariff::getWeightRate(); }

float AirExpressTariff::getTimeRate() const { return Tariff::getTimeRate(); }
