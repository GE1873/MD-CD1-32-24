#ifndef EXPRESSDELIVERY_H
#define EXPRESSDELIVERY_H

#include "ideliverystrategy.h"
#include "tariff.h"
#include <memory>

///
/// \brief The GroundExpressDelivery class
///
class GroundExpressDelivery : public IDeliveryStrategy
{
public:
    GroundExpressDelivery( std::unique_ptr<Tariff> tariff );

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

#endif // EXPRESSDELIVERY_H
