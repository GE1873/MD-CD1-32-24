#include "groundexpresstariff.h"

GroundExpressTariff::GroundExpressTariff()
{
}

void GroundExpressTariff::setDistanceRate( float distanceRate ) { Tariff::setDistanceRate( distanceRate ); }

void GroundExpressTariff::setTimeRate( float timeRate ) { Tariff::setTimeRate( timeRate ); }

float GroundExpressTariff::getDistanceRate() const { return Tariff::getDistanceRate(); }

float GroundExpressTariff::getTimeRate() const { return Tariff::getTimeRate(); }
