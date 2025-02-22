#ifndef IDELIVERYSTRATEGY_H
#define IDELIVERYSTRATEGY_H

///
/// \brief The IDeliveryStrategy interface class
///
class IDeliveryStrategy
{
public:
    virtual ~IDeliveryStrategy() = default;

    ///
    /// \brief Calculates delivery costs
    /// \param weight
    /// \param distance
    /// \return
    ///
    virtual float calculateCost( float weight, float distance ) const = 0;
};

#endif // IDELIVERYSTRATEGY_H
