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
    for(int i {1}; i <= 10; i++){

        for(int j {1}; j <= 3; j++){
            std::cout << std::left << std::setw(15) << std::to_string(j) + " * " + std::to_string(i) + " = " + std::to_string(i * j) << std::setw(5) << "|";
            if(j == 3) {
                std::cout << std::endl;
            }
        }
    }
    std::cout << "-------------------------------------------------------" << std::endl;
    for(int i {1}; i <= 10; i++){

        for(int j {4}; j <= 6; j++){
            std::cout << std::left << std::setw(15) << std::to_string(j) + " * " + std::to_string(i) + " = " + std::to_string(i * j) << std::setw(5) << "|";
            if(j == 6) {
                std::cout << std::endl;
            }
        }
    }
    std::cout << "-------------------------------------------------------" << std::endl;
    for(int i {1}; i <= 10; i++){

        for(int j {7}; j <= 9; j++){
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
    int i {0};
    int j {0};
    std::cout << "-------------------------------------------------------" << std::endl;
    std::cout << std::left << std::setw(55)  << "Creating a multiplication table using a WHILE loop" << std::setw(5) << "|" << std::endl;
    std::cout << "-------------------------------------------------------" << std::endl;
    while(i < 10){
        i++;
        j = 0;
        while(j < 3){
            j++;
            std::cout << std::left << std::setw(15) << std::to_string(j) + " * " + std::to_string(i) + " = " + std::to_string(i * j) << std::setw(5) << "|";
            if(j == 3) {
                std::cout << std::endl;
            }
        }
    }
    std::cout << "-------------------------------------------------------" << std::endl;
    i = 0;
    while(i < 10){
        i++;
        j = 3;
        while(j < 6){
            j++;
            std::cout << std::left << std::setw(15) << std::to_string(j) + " * " + std::to_string(i) + " = " + std::to_string(i * j) << std::setw(5) << "|";
            if(j == 6) {
                std::cout << std::endl;
            }
        }
    }
    std::cout << "-------------------------------------------------------" << std::endl;
    i = 0;
    while(i < 10){
        i++;
        j = 6;
        while(j < 9){
            j++;
            std::cout << std::left << std::setw(15) << std::to_string(j) + " * " + std::to_string(i) + " = " + std::to_string(i * j) << std::setw(5) << "|";
            if(j == 9) {
                std::cout << std::endl;
            }
        }
    }
    std::cout << "-------------------------------------------------------" << std::endl;
}

void MultiplicationTable::mtUsingDoWhile() const
{
    int i {0};
    int j {0};
    std::cout << "-------------------------------------------------------" << std::endl;
    std::cout << std::left << std::setw(55)  << "Creating a multiplication table using a DO-WHILE loop" << std::setw(5) << "|" << std::endl;
    std::cout << "-------------------------------------------------------" << std::endl;
    do{
        i++;
        j = 0;
        while(j < 3){
            j++;
            std::cout << std::left << std::setw(15) << std::to_string(j) + " * " + std::to_string(i) + " = " + std::to_string(i * j) << std::setw(5) << "|";
            if(j == 3) {
                std::cout << std::endl;
            }
        }
    } while(i < 10);
    std::cout << "-------------------------------------------------------" << std::endl;
    i = 0;
    do{
        i++;
        j = 3;
        while(j < 6){
            j++;
            std::cout << std::left << std::setw(15) << std::to_string(j) + " * " + std::to_string(i) + " = " + std::to_string(i * j) << std::setw(5) << "|";
            if(j == 6) {
                std::cout << std::endl;
            }
        }
    }while(i < 10);
    std::cout << "-------------------------------------------------------" << std::endl;
    i = 0;
    do{
        i++;
        j = 6;
        while(j < 9){
            j++;
            std::cout << std::left << std::setw(15) << std::to_string(j) + " * " + std::to_string(i) + " = " + std::to_string(i * j) << std::setw(5) << "|";
            if(j == 9) {
                std::cout << std::endl;
            }
        }
    }while(i < 10);
    std::cout << "-------------------------------------------------------" << std::endl;
}
