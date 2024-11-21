#include "multiplicationtable.h"

#include <iostream>
#include <iomanip>

MultiplicationTable::MultiplicationTable()
{

}

void MultiplicationTable::mtUsingFor() const
{
    std::cout << "-------------------------------------------------------" << std::endl;
    std::cout << std::left << std::setw(55)  << "Creating a multiplication table using a FOR loop" << std::setw(5) << "|" << std::endl;
    std::cout << "-------------------------------------------------------" << std::endl;
    for(int i = 1; i <= 10; i++){

        for(int j = 1; j <= 3; j++){
            std::cout << std::left << std::setw(15) << std::to_string(j) + " * " + std::to_string(i) + " = " + std::to_string(i * j) << std::setw(5) << "|";
            if(j == 3) {
                std::cout << std::endl;
            }
        }
    }
    std::cout << "-------------------------------------------------------" << std::endl;
    for(int i = 1; i <= 10; i++){

        for(int j = 4; j <= 6; j++){
            std::cout << std::left << std::setw(15) << std::to_string(j) + " * " + std::to_string(i) + " = " + std::to_string(i * j) << std::setw(5) << "|";
            if(j == 6) {
                std::cout << std::endl;
            }
        }
    }
    std::cout << "-------------------------------------------------------" << std::endl;
    for(int i = 1; i <= 10; i++){

        for(int j = 7; j <= 9; j++){
            std::cout << std::left << std::setw(15) << std::to_string(j) + " * " + std::to_string(i) + " = " + std::to_string(i * j) << std::setw(5) << "|";
            if(j == 9) {
                std::cout << std::endl;
            }
        }
    }
    std::cout << "-------------------------------------------------------" << std::endl;
}

void MultiplicationTable::mtUsingWhile() const
{

}

void MultiplicationTable::mtUsingDoWhile() const
{

}
