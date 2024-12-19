#include "forest.h"
//#include "tree.h"

#include <ctime>
#include <iostream>
#include <iomanip>
#include <memory>

int main(){
    std::srand(std::time(0));

    auto upForest1 = std::make_unique<Forest>();
    if(upForest1){
        upForest1->autoPlantForest();
        std::cout << std::left << std::setw(25) << "Number of trees in the forest : " << std::setw(25) << upForest1->getTreesNumber() << std::endl;
    }else{
        std::cerr << "Error : Forest class object is undefined!";
        std::cout << std::endl;
        exit(EXIT_FAILURE);
    }

    auto upForest2 = std::make_unique<Forest>();
    if(upForest2){
        upForest2->autoPlantForest();
        std::cout << std::left << std::setw(25) << "Number of trees in the forest : " << std::setw(25) << upForest2->getTreesNumber() << std::endl;
    }else{
        std::cerr << "Error : Forest class object is undefined!";
        std::cout << std::endl;
        exit(EXIT_FAILURE);
    }


    //    auto upTree = std::make_unique<Tree>(static_cast<Tree::TREE_TYPE>(0 + (rand() % 5)));
    //    if(upTree){
    //        upTree->wind();
    //    }else{
    //        std::cerr << "Error : Test class object is undefined!";
    //        std::cout << std::endl;
    //        exit(EXIT_FAILURE);
    //    }

    //    auto upTree2 = std::make_unique<Tree>(*upTree);
    //    if(upTree2){
    //        upTree2->wind();
    //    }else{
    //        std::cerr << "Error : Test class object is undefined!";
    //        std::cout << std::endl;
    //        exit(EXIT_FAILURE);
    //    }

    //    auto upTree3 = std::make_unique<Tree>(static_cast<Tree::TREE_TYPE>(0 + (rand() % 5)));
    //    if(upTree3){
    //        upTree3->wind();
    //    }else{
    //        std::cerr << "Error : Test class object is undefined!";
    //        std::cout << std::endl;
    //        exit(EXIT_FAILURE);
    //    }

    //    auto upTree4 = std::make_unique<Tree>(*upTree3);
    //    if(upTree4){
    //        upTree4->wind();
    //    }else{
    //        std::cerr << "Error : Test class object is undefined!";
    //        std::cout << std::endl;
    //        exit(EXIT_FAILURE);
    //    }

    return 0;
}
