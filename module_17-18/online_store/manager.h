#ifndef MANAGER_H
#define MANAGER_H

#include "order.h"
#include <vector>

///
/// \brief The Manager class for describing the work of the manager
///
class Manager
{
public:
    Manager();
    ~Manager();

    ///
    /// \brief Adds order
    /// \param orderAmount
    ///
    void addOrder( double orderAmount );

    ///
    /// \brief Processing the order
    ///
    void processOrders();

    ///
    /// \brief Prints incoming orders
    ///
    void printIncomingOrders() const;

    ///
    /// \brief Print processing orders
    ///
    void printProcessingOrders() const;

private:
    void printOrders( const std::vector<Order>& orders ) const;

    std::vector<Order> _orders{};
    std::vector<Order> _processingOrders{};
};

#endif // MANAGER_H
