#include "manager.h"
#include <algorithm>
#include <chrono>
#include <iomanip>
#include <iostream>
#include <thread>
#include <vector>

int main()
{
    Manager manager;

    manager.addOrder( 1000 );
    std::this_thread::sleep_for( std::chrono::seconds( 1 ) );
    manager.addOrder( 20000 );
    std::this_thread::sleep_for( std::chrono::seconds( 2 ) );
    manager.addOrder( 30000 );
    std::this_thread::sleep_for( std::chrono::seconds( 3 ) );
    manager.addOrder( 4000 );
    std::this_thread::sleep_for( std::chrono::seconds( 4 ) );
    manager.addOrder( 50000 );
    std::this_thread::sleep_for( std::chrono::seconds( 5 ) );

    std::cout << "------------------------------------------------------" << std::endl;
    std::cout << std::left << std::setw( 30 ) << "Incoming Orders : " << std::endl;
    manager.printIncomingOrders();

    manager.processOrders();

    std::cout << "------------------------------------------------------" << std::endl;
    std::cout << std::left << std::setw( 30 ) << "Orders in Processing : " << std::endl;
    manager.printProcessingOrders();

    std::cout << "------------------------------------------------------" << std::endl;
    std::cout << std::left << std::setw( 30 ) << "Remaining Orders : " << std::endl;
    manager.printIncomingOrders();

    return 0;
}
