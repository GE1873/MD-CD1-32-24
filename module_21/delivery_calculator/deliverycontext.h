#ifndef DELIVERYCONTEXT_H
#define DELIVERYCONTEXT_H

#include "ideliverystrategy.h"
#include <memory>

///
/// \brief The DeliveryContext class
///
class DeliveryContext
{
public:
    DeliveryContext() = default;

    ///
    /// \brief Sets delivery strategy
    /// \param strategy
    ///
    void setStrategy( std::unique_ptr<IDeliveryStrategy> strategy );

    ///
    /// \brief Calculates delivery costs
    /// \param weight
    /// \param distance
    /// \return
    ///
    float calculateCost( float weight, float distance ) const;

private:
    std::unique_ptr<IDeliveryStrategy> _strategy{};
};

#endif // DELIVERYCONTEXT_H
