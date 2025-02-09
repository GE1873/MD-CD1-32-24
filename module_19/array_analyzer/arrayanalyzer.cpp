#include "arrayanalyzer.h"
#include <iomanip>
#include <iostream>
#include <random>
#include <future>

void ArrayAnalyzer::setArraySize( size_t size )
{
    _size = size;
    _data.resize( size );
}

void ArrayAnalyzer::addMethod( MethodName methodName )
{
    _methods[methodName] = getMethod( methodName );
}

void ArrayAnalyzer::fillArray()
{
    if( _size <= 0 ) throw std::invalid_argument( "Error : Invalid array size!" );
    for ( size_t i{}; i < _size; ++i ) {
        _data[i] = 0 + (rand() % 101);
    }
}

void ArrayAnalyzer::analyzeArray()
{
    if( _methods.empty() ) throw std::invalid_argument( "Error : There are no methods for analysis!" );
    for( const auto& method : _methods ) {
        if( method.second ) {
            std::promise<int> promise;
            _futures[method.first] = promise.get_future();
            _threads.emplace_back( method.second, std::move( promise ) );
        }
        else std::cerr << "Error : Method for " + getMethodName( method.first ) + " is undefined!" << std::endl;
    }

    for ( auto& thread : _threads ) {
        thread.join();
    }
}

void ArrayAnalyzer::printArray() const
{
    for( const int num : _data ) {
        std::cout << num <<  std::endl;
    }
}

void ArrayAnalyzer::printResults()
{
    std::cout << "------------------------------------------------------" << std::endl;
    for ( auto& future : _futures ) {
        if( future.second.valid() ) {
            int result = future.second.get();
            std::cout << std::left << getMethodName( future.first ) << std::setw( 5 ) << " : " << result << std::endl;
        }
        else std::cerr << "Error : Result for " + getMethodName( future.first ) + " already received!" << std::endl;
    }
}

std::function<void ( std::promise<int> )> ArrayAnalyzer::getMethod( MethodName methodName ) {
    if ( methodName == MethodName::Sum ) {
        return [this]( std::promise<int> promise ){
            int sum{};
            for ( size_t i{}; i < this->_size; ++i ) {
                sum += this->_data[i];
            }
            promise.set_value( sum );
        };
    }
    else if( methodName == MethodName::Min ) {
        return [this]( std::promise<int> promise ){
            int min{this->_data[0]};
            for ( size_t i{1}; i < this->_size; ++i ) {
                if ( this->_data[i] < min ) {
                    min = this->_data[i];
                }
            }
            promise.set_value( min );
        };
    }
    else if( methodName == MethodName::Max ) {
        return [this]( std::promise<int> promise ){
            int max{this->_data[0]};
            for ( size_t i{1}; i < this->_size; ++i ) {
                if ( this->_data[i] > max ) {
                    max = this->_data[i];
                }
            }
            promise.set_value( max );
        };
    }
    else if( methodName == MethodName::Unknown ) {
        return nullptr;
    }
    else return nullptr;
}

std::string ArrayAnalyzer::getMethodName( MethodName methodName ) const
{
    std::string res{};
    switch ( methodName ) {
    case MethodName::Sum:
        res = "Sum";
        break;
    case MethodName::Min:
        res = "Min";
        break;
    case MethodName::Max:
        res = "Max";
        break;
    case MethodName::Unknown:
        res = "Unknown";
        break;
    default:
        res = "Unknown";
        break;
    }
    return res;
}
