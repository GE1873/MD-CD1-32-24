#include "car.h"
#include <memory>

Car::Car( std::string name, bool isRepaired ) : _name{ name }, _isRepaired{ isRepaired }
{}

void Car::repair()
{
    if( !_isRepaired ) _isRepaired = true;
}

std::string Car::getName() const
{
    return _name;
}

bool Car::isRepaired() const
{
    return _isRepaired;
}

std::ostream& operator<<( std::ostream& os, const Car* car )
{
    os << std::left << std::setw( 25 ) << "Car name is : " << std::setw( 25 ) << car->getName() << std::endl;
    os << std::boolalpha << std::left << std::setw( 25 ) << "Car repair status is : " << std::setw( 25 ) << car->isRepaired() << std::endl;
    return os;
}
