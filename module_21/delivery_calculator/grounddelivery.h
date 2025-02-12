#ifndef GROUNDDELIVERY_H
#define GROUNDDELIVERY_H

#include "ideliverystrategy.h"
#include "tariff.h"
#include <memory>

///
/// \brief The GroundDelivery class
///
class GroundDelivery : public IDeliveryStrategy
{
public:
    GroundDelivery( std::unique_ptr<Tariff> tariff );

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

#endif // GROUNDDELIVERY_H
