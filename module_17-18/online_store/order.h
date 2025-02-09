#ifndef ORDER_H
#define ORDER_H

#include <ctime>
#include <string>

///
/// \brief The Order class for describing and working with an order
///
class Order
{
public:
    Order( double orderAmount );

    ///
    /// \brief Move constructor
    /// \param order
    ///
    Order( Order&& order );

    ///
    /// \brief Copy constructor
    /// \param order
    ///
    Order( Order& order );

    enum class OrderStatus {
        Unknown = -1,
        New = 1,
        Processing = 2,
        Shipped = 3
    };

    ///
    /// \brief Converts the order status into a readable form
    /// \param status
    /// \return
    ///
    std::string getOrderStatusName( OrderStatus status ) const;

    ///
    /// \brief Updates order status
    /// \param status
    ///
    void updateStatus( OrderStatus status );

    ///
    /// \brief Move assignment operator
    /// \param order
    /// \return
    ///
    Order& operator=( Order&& order );

    ///
    /// \brief Getters
    ///
    double getOrderAmount() const;
    time_t getOrderDate() const;
    OrderStatus getOrderStatus() const;
    int getOrderNumber() const;

private:
    std::time_t createOrderDate() const;

    double _orderAmount{};
    std::time_t _orderDate{createOrderDate()};
    OrderStatus _orderStatus{OrderStatus::New};
    inline static int _counter{};
    int _orderNumber{};
};

#endif // ORDER_H
