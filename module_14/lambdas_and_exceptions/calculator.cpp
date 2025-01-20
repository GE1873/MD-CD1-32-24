#include "calculator.h"
#include "invalidlogargument.h"
#include "invalidradusargument.h"

Calculator::Calculator(){
    _methods.resize(4);

    _methods[static_cast<int>( MethodName::DIVISION )] = [] ( double value1, double value2 ){
        if(value2 == 0) throw std::invalid_argument( "Error : The divisor is zero!" );
        return value1/value2;
    };

    _methods[static_cast<int>( MethodName::SQUARE_ROOT )] = [] ( double value1, double value2 ){
        if (value1 < 0) throw std::domain_error( "Error : The number is negative!" );
        return sqrt(value1);
    };

    _methods[static_cast<int>( MethodName::LOGARITHM )] = [] ( double value1, double value2 ){
        if (value1 < 0) throw InvalidLogArgument( "Error : The number is negative!" );
        return log(value1);
    };

    _methods[static_cast<int>( MethodName::CIRCLE_AREA )] = [] ( double value1, double value2 ){
        if (value1 < 0) throw InvalidRadusArgument( "Error : The number is negative!" );
        return M_PI * value1 * value1;
    };
}

double Calculator::calculate( const MethodName method, double value1, double value2 ){
    if( method != MethodName::UNKNOWN ){
        auto _method = getMethod( method );
        if(_method) {
            return _method( value1, value2 );
        } else return 0.0;
    }else return 0.0;
}

std::function<double( double, double )> Calculator::getMethod( const MethodName method ) const{
    return _methods[static_cast<int>( method )];
}
