#include "tree.h"

#include <ctime>
#include <iostream>
#include <memory>

int main(){
    std::srand(std::time(0));
    auto upTree = std::make_unique<Tree>(Tree::TREE_TYPE::PINE);
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

    auto upTree3 = std::make_unique<Tree>(Tree::TREE_TYPE::OAK);
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
