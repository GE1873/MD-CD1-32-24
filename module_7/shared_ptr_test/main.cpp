#include "sharedptrtest.h"

#include <iostream>

int main(){

    SharedPtrTest spt;
    spt.setArraySize();
    spt.createArray();

    std::weak_ptr<int[]> wptr {spt.getSharedPtr()};

    std::cout << "Sum of the array equal : " << spt.sumArray(wptr) << std::endl;

    const auto [minNum, maxNum] = spt.getMinMaxNum(wptr);
    std::cout << "------------------------------------------------------" << std::endl;
    std::cout << "Maximum number in array is : " << maxNum << std::endl;
    std::cout << "Minimum number in array is : " << minNum << std::endl;
    std::cout << "------------------------------------------------------" << std::endl;

    return 0;    
}
