#include "funcoverloadtest.h"

#include <iostream>

int main(){
    auto upFot = std::make_unique<FuncOverloadTest>();
    if(upFot){
        upFot->runTest();
    }else{
        std::cerr << "Error : Test class object is undefined!";
        std::cout << std::endl;
        exit(EXIT_FAILURE);
    }
    return 0;
}
