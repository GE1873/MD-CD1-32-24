#ifndef AIREXPRESSDELIVERY_H
#define AIREXPRESSDELIVERY_H

#include "ideliverystrategy.h"
#include "tariff.h"
#include <memory>

///
/// \brief The AirExpressDelivery class
///
class AirExpressDelivery : public IDeliveryStrategy
{
public:
    AirExpressDelivery( std::unique_ptr<Tariff> tariff );

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

#endif // AIREXPRESSDELIVERY_H
