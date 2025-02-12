#ifndef GROUNDEXPRESSTARIFF_H
#define GROUNDEXPRESSTARIFF_H

#include "tariff.h"

///
/// \brief The GroundExpressTariff class
///
class GroundExpressTariff : public Tariff
{
public:
    GroundExpressTariff();

    ///
    /// \brief Get and set methods for distance and time rate
    /// \param distanceRate
    ///
    void setDistanceRate( float distanceRate );
    void setTimeRate( float timeRate );
    float getDistanceRate() const;
    float getTimeRate() const;
};

#endif // GROUNDEXPRESSTARIFF_H
