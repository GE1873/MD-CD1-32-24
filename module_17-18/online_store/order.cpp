#include "order.h"
#include <iostream>

Order::Order( double orderAmount ) : _orderAmount{ orderAmount }
{
    _orderNumber = ++_counter;
    std::cout << "The order number " << _orderNumber <<" created! (constructor)" << std::endl;
}

Order::Order( Order&& order )
{
    this->_orderAmount = order._orderAmount;
    this->_orderDate = order._orderDate;
    this->_orderStatus = order._orderStatus;
    this->_orderNumber = order._orderNumber;
    std::cout << "The order moved! (move constructor)" << std::endl;
}

Order::Order( Order& order )
{
    _orderAmount = order._orderAmount;
    _orderDate = createOrderDate();
    _orderStatus = OrderStatus::New;
    _orderNumber = ++_counter;
    std::cout << "The order copyed! (copy constructor)" << std::endl;
}

std::time_t Order::createOrderDate() const
{
    time_t now = time( 0 );
    tm* ltm = localtime( &now );
    return std::mktime( ltm );
}

int Order::getOrderNumber() const
{
    return _orderNumber;
}

Order& Order::operator=( Order&& order )
{
    if ( this != &order ) {
        this->_orderAmount = order._orderAmount;
        this->_orderDate = order._orderDate;
        this->_orderStatus = order._orderStatus;
        this->_orderNumber = order._orderNumber;
        std::cout << "The order moved! (move assignment operator)" << std::endl;
    }
    return *this;
}

Order::OrderStatus Order::getOrderStatus() const
{
    return _orderStatus;
}

std::time_t Order::getOrderDate() const
{
    return _orderDate;
}

std::string Order::getOrderStatusName( OrderStatus status ) const
{
    std::string res{};
    switch ( status ) {
    case OrderStatus::New:
        res = "New";
        break;
    case OrderStatus::Processing:
        res = "Processing";
        break;
    case OrderStatus::Shipped:
        res = "Shipped";
        break;
    case OrderStatus::Unknown:
        res = "Unknown";
        break;
    default:
        res = "Unknown";
        break;
    }
    return res;
}

void Order::updateStatus( OrderStatus status )
{
    _orderStatus = status;
}

double Order::getOrderAmount() const
{
    return _orderAmount;
}
