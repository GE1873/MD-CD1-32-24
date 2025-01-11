#ifndef CAR_H
#define CAR_H

#include <iomanip>
#include <memory>
#include <string>

///
/// \brief The Car class
///
class Car
{
public:
    explicit Car( std::string name, bool isRepaired = false );
    virtual ~Car() = default;

    ///
    /// \brief Repairs the car
    ///
    void repair();

    ///
    /// \brief Gets the name of the car
    /// \return
    ///
    std::string getName() const;

    ///
    /// \brief Gets the status of the car repair
    /// \return
    ///
    bool isRepaired() const;

protected:    
    friend std::ostream& operator<<( std::ostream& os, const Car* car );

private:
    std::string _name{};
    bool _isRepaired{};
};

#endif // CAR_H
