#include "matrixcreator.h"
#include <iomanip>
#include <iostream>
#include <ostream>

MatrixCreator::MatrixCreator()
{

}

void MatrixCreator::createAndPrintMatrix()
{
    std::cout << "******************************************************" << std::endl;
    std::cout << "Create matrix 3X3" << std::endl;
    std::cout << "******************************************************" << std::endl;
    int rows {3};
    int columns {3};
    int** m = new int*[rows];    
    for(int i {}; i < rows; ++i){
        m[i] = new int[columns];
        std::cout << std::left;
        for(int j {}; j < columns; ++j){
            m[i][j] = i * j;
            std::cout << std::setw(5)  << m[i][j] << std::setw(5) << "|";
        }
        std::cout << std::endl;
        std::cout << "-------------------------" << std::endl;
    }
    for (int i {}; i < rows; ++i)
        delete [] m[i];
    delete [] m;
}
