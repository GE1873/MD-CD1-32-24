#include "tree.h"

#include <ctime>
#include <iostream>
#include <memory>

int main(){
    std::srand(std::time(0));
    auto upTree = std::make_unique<Tree>(static_cast<Tree::TREE_TYPE>(0 + (rand() % 5)));
    if(upTree){
        upTree->wind();
    }else{
        std::cerr << "Error : Test class object is undefined!";
        std::cout << std::endl;
        exit(EXIT_FAILURE);
    }

    auto upTree2 = std::make_unique<Tree>(*upTree);
    if(upTree2){
        upTree2->wind();
    }else{
        std::cerr << "Error : Test class object is undefined!";
        std::cout << std::endl;
        exit(EXIT_FAILURE);
    }

    auto upTree3 = std::make_unique<Tree>(static_cast<Tree::TREE_TYPE>(0 + (rand() % 5)));
    if(upTree3){
        upTree3->wind();
    }else{
        std::cerr << "Error : Test class object is undefined!";
        std::cout << std::endl;
        exit(EXIT_FAILURE);
    }

    auto upTree4 = std::make_unique<Tree>(*upTree3);
    if(upTree4){
        upTree4->wind();
    }else{
        std::cerr << "Error : Test class object is undefined!";
        std::cout << std::endl;
        exit(EXIT_FAILURE);
    }

    return 0;
}
