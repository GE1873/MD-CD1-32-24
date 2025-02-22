#ifndef AIRDELIVERY_H
#define AIRDELIVERY_H

#include "ideliverystrategy.h"
#include "tariff.h"
#include <memory>

///
/// \brief The AirDelivery class
///
class AirDelivery : public IDeliveryStrategy
{
public:
    AirDelivery( std::unique_ptr<Tariff> tariff );

    ///
    /// \brief Calculates delivery costs
    /// \param weight
    /// \param distance
    /// \return
    ///
    float calculateCost( float weight, float distance ) const override;

private:
    std::unique_ptr<Tariff> _tariff{};
};

#endif // AIRDELIVERY_H
