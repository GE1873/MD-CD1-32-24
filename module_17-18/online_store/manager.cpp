#include "manager.h"
#include <algorithm>
#include <iomanip>
#include <iostream>
//#include <chrono>
//#include <ctime>

Manager::Manager()
{
    _orders.reserve(100);
}

Manager::~Manager()
{
    _orders.clear();
    _processingOrders.clear();
}

void Manager::addOrder( double orderAmount )
{
    if( _orders.size() >= 100 ) {
        std::cout << "Too many orders, please wait." << std::endl;
    } else _orders.emplace_back( orderAmount );
}

void Manager::processIncomingOrders()
{
    std::transform( make_move_iterator( _orders.begin() ), make_move_iterator( _orders.end() ), _orders.begin(),
                   []( Order order ) {
                       time_t now = time( 0 );
                       tm* ltm = localtime( &now );
                       std::time_t th1 = std::mktime( ltm );
                       std::time_t th2 = order.getOrderDate();
                       if( std::difftime( th1, th2 ) > 5 ) order.updateStatus( Order::OrderStatus::Processing );
                       return order;
                   });

    auto oi = std::find_if( _orders.begin(), _orders.end(),
                           []( const Order& o ) { return o.getOrderAmount() > 5000 && o.getOrderStatus() == Order::OrderStatus::Processing;} );

    std::cout << std::left << std::setw(30) << "First order number over 5000 is " <<  oi->getOrderNumber() << " in amount " <<  oi->getOrderAmount() << std::endl;

    auto poi = std::partition( _orders.begin(), _orders.end(), []( const Order& o )
                              {
                                  return o.getOrderStatus() == Order::OrderStatus::Processing;
                              });

    _processingOrders.insert( _processingOrders.end(),
                             std::make_move_iterator( _orders.begin() ),
                             std::make_move_iterator( poi ) );

    _orders.erase( _orders.begin(), poi );
}

void Manager::printIncomingOrders() const
{
    printOrders( _orders );
}

void Manager::printProcessingOrders() const
{
    printOrders( _processingOrders );
}

void Manager::printOrders( const std::vector<Order>& orders ) const
{
    for( const auto& order : orders ) {
        std::cout << "------------------------------------------------------" << std::endl;
        std::cout << std::left << std::setw( 30 ) << "Order number : " <<  order.getOrderNumber() << std::endl;
        std::cout << std::left << std::setw( 30 ) << "Order status : " <<  order.getOrderStatusName( order.getOrderStatus() ) << std::endl;
        std::cout << std::left << std::setw( 30 ) << "Order amount : " <<  order.getOrderAmount() << std::endl;
        std::time_t t = order.getOrderDate();
        std::cout << std::left << std::setw( 30 ) << "Order date : " << std::put_time(std::localtime(&t), "%B %d, %Y, %H:%M:%S") << std::endl;
    }
}
