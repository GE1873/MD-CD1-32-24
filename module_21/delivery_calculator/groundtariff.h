#ifndef GROUNDTARIFF_H
#define GROUNDTARIFF_H

#include "tariff.h"

///
/// \brief The GroundTariff class
///
class GroundTariff : public Tariff
{
public:
    GroundTariff();

    ///
    /// \brief Get and set methods for distance rate
    /// \param distanceRate
    ///
    void setDistanceRate( float distanceRate );
    float getDistanceRate() const;
};

#endif // GROUNDTARIFF_H
