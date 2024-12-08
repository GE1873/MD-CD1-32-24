#include "../inc/stringreverser.h"
#include "../inc/matrixcreator.h"
#include "../inc/vectorsorter.h"
#include "../inc/arrayanalyzer.h"

#include <ctime>
#include <iostream>

int main()
{
    ///
    /// \brief Module 6 : Reverse the entered string, create matrix 3X3, vector sorting, array analyzing
    ///
    StringReverser r;
    MatrixCreator mm;
    VectorSorter vm;
    ArrayAnalyzer spm;

    r.reverseAndPrintEnteredString();
    mm.createAndPrintMatrix();
    vm.createAndPrintVector();
    spm.createAndAnalizeArray();
    ///
    ///

    return 0;    
}
