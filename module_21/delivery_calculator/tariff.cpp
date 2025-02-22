#include "tariff.h"
#include <iostream>

void Tariff::setDistanceRate( float distanceRate ) { _distanceRate = distanceRate; }

void Tariff::setWeightRate( float weightRate ) { _weightRate = weightRate; }

void Tariff::setTimeRate( float timeRate ) { _timeRate = timeRate; }

float Tariff::getDistanceRate() const { return _distanceRate; }

float Tariff::getWeightRate() const { return _weightRate; }

float Tariff::getTimeRate() const { return _timeRate; }
