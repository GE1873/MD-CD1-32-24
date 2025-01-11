#ifndef SERVICESTATION_H
#define SERVICESTATION_H

#include <iostream>
#include <memory>
#include <vector>

///
/// \brief The ServiceStation template class
///
template <typename T>
class ServiceStation
{
public:
    ServiceStation( size_t carsLimit = 5 ): _carsLimit{ carsLimit }
    {}

    ~ServiceStation()
    {
        if ( !_cars.empty() ){           
            _cars.clear();
        }
    }

    ///
    /// \brief Adds cars to the service station
    /// \param car
    ///
    void addCar( std::shared_ptr<T> car )
    {
        if( car ){
            if( _cars.size() < _carsLimit ) {
                _cars.push_back( car );
            } else std::cerr << "The limit of cars at the service station has been exceeded, please wait" << std::endl;
        } else throw std::invalid_argument( "Error : Car class object is undefined!" );
    }

    ///
    /// \brief Repairs all cars at the service station
    ///
    void repairAll()
    {
        for( std::shared_ptr<T> car : _cars ){
            car->repair();
            try{
                _garage.addToGarage( car );
            }
            catch ( const std::invalid_argument& e ){
                throw e;
            }
        }
        _cars.clear();
    }

    ///
    /// \brief Displays the contents of the garage
    ///
    void displayGarage() const
    {
        _garage.displayAll();
    }

    ///
    /// \brief Displays the contents of the service station
    ///
    void displayServiceStation()
    {
        if( !_cars.empty() ){
            for( const std::shared_ptr<T> car : _cars ){
                std::cout << car << std::endl;
            }
        } else std::cout << "There are no cars for repairs" << std::endl;
    }

private:
    std::vector<std::shared_ptr<T>> _cars{};
    size_t _carsLimit{};

    template <typename C>
    class Garage
    {
    public:
        Garage() = default;
        ~Garage()
        {
            if ( !_cars.empty() ){               
                _cars.clear();
            }
        }

        ///
        /// \brief Adds cars to the garage
        /// \param car
        ///
        void addToGarage( std::shared_ptr<C> car )
        {
            if( car ){
                _cars.push_back( car );
            } else throw std::invalid_argument( "Error : Car class object is undefined!" );
        }

        ///
        /// \brief Displays all cars in the garage
        ///
        void displayAll() const
        {
            for( const std::shared_ptr<C> car : _cars ){
                std::cout << car << std::endl;
            }
        }

    private:
        std::vector<std::shared_ptr<C>> _cars{};
    };

    Garage<T> _garage{};
};

#endif // SERVICESTATION_H
