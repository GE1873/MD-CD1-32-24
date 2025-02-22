#ifndef DELIVERYSTRATEGYFACTORY_H
#define DELIVERYSTRATEGYFACTORY_H

#include "ideliverystrategy.h"
#include "tariff.h"
#include <map>
#include <memory>
#include <string>

///
/// \brief The DeliveryStrategyFactory class for creating strategies
///
class DeliveryStrategyFactory
{
public:
    enum class DeliveryTypes
    {
        Unknown,
        Ground,
        Ground_Express,
        Air,
        Air_Express
    };

    ///
    /// \brief Sets delivery tariff
    /// \param type
    /// \param tariff
    ///
    void setTariff( DeliveryTypes type, std::unique_ptr<Tariff> tariff );

    ///
    /// \brief Creates strategy
    /// \param type
    /// \return
    ///
    std::unique_ptr<IDeliveryStrategy> createStrategy( DeliveryTypes type );

private:
    std::map<DeliveryTypes, std::unique_ptr<Tariff>> _tariffs{};
};

#endif // DELIVERYSTRATEGYFACTORY_H




