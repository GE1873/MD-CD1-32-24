#ifndef AIRTARIFF_H
#define AIRTARIFF_H

#include "tariff.h"

///
/// \brief The AirTariff class
///
class AirTariff : public Tariff
{
public:
    AirTariff();

    ///
    /// \brief Get and set methods for distance and weight rate
    /// \param distanceRate
    ///
    void setDistanceRate( float distanceRate );
    void setWeightRate( float weightRate );
    float getDistanceRate() const;
    float getWeightRate() const;
};

#endif // AIRTARIFF_H
