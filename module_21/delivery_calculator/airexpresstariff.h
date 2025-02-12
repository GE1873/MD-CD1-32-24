#ifndef AIREXPRESSTARIFF_H
#define AIREXPRESSTARIFF_H

#include "tariff.h"

///
/// \brief The AirExpressTariff class
///
class AirExpressTariff : public Tariff
{
public:
    AirExpressTariff();

    ///
    /// \brief Get and set methods for distance, weight and time rate
    /// \param distanceRate
    ///
    void setDistanceRate( float distanceRate );
    void setWeightRate( float weightRate );
    void setTimeRate( float timeRate );
    float getDistanceRate() const;
    float getWeightRate() const;
    float getTimeRate() const;
};

#endif // AIREXPRESSTARIFF_H
