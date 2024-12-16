#include "uniqueptrtest.h"

#include <iostream>

int main(){
    auto upUpt {std::make_unique<UniquePtrTest>()};
    if(upUpt){
        upUpt->runTest();
    }else{
        std::cerr << "Error : Test class object is undefined!";
        std::cout << std::endl;
        exit(EXIT_FAILURE);
    }
    return 0;    
}
