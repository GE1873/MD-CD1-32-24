#include "forest.h"

#include <ctime>
#include <iostream>
#include <iomanip>
#include <memory>

int main(){
    std::srand(std::time(0));

    auto upForest1 = std::make_shared<Forest>();
    if(upForest1){
        upForest1->autoPlantForest();
        std::cout << std::left << std::setw(25) << "Number of trees in the forest : " << std::setw(25) << upForest1->getTreesNumber() << std::endl;
    }else{
        std::cerr << "Error : Forest class object is undefined!";
        std::cout << std::endl;
        exit(EXIT_FAILURE);
    }

    auto upForest2 = std::make_shared<Forest>();
    if(upForest2){
        upForest2->autoPlantForest();
        std::cout << std::left << std::setw(25) << "Number of trees in the forest : " << std::setw(25) << upForest2->getTreesNumber() << std::endl;
    }else{
        std::cerr << "Error : Forest class object is undefined!";
        std::cout << std::endl;
        exit(EXIT_FAILURE);
    }

    auto upForest3 = *upForest1 + upForest2;

    if(upForest3){
        std::cout << std::left << std::setw(25) << "Number of trees in the forest : " << std::setw(25) << upForest3->getTreesNumber() << std::endl;
    }else{
        std::cerr << "Error : Forest class object is undefined!";
        std::cout << std::endl;
        exit(EXIT_FAILURE);
    }

    if(upForest2){
        upForest2->cutAll();
        std::cout << std::left << std::setw(25) << "Number of trees in the forest : " << std::setw(25) << upForest2->getTreesNumber() << std::endl;
    }else{
        std::cerr << "Error : Forest class object is undefined!";
        std::cout << std::endl;
        exit(EXIT_FAILURE);
    }

    return 0;
}
