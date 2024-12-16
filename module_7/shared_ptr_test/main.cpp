#include "sharedptrtest.h"

#include <iostream>

int main(){
    auto upSpt {std::make_unique<SharedPtrTest>()};
    if(upSpt){
        upSpt->runTest();
    }else{
        std::cerr << "Error : Test class object is undefined!";
        std::cout << std::endl;
        exit(EXIT_FAILURE);
    }
    return 0;    
}
