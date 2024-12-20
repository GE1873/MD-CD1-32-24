#include "forest.h"

#include <ctime>
#include <iostream>
#include <iomanip>
#include <memory>

int main(){
    std::srand(std::time(0));

    auto spForest1 = std::make_shared<Forest>();
    if(spForest1){
        spForest1->autoPlantForest(100);

        std::cout << std::left << std::setw(25) << "Number of trees in the first forest : " << std::setw(25) << spForest1->getTreesNumber() << std::endl;

        Tree* tree = new Tree(static_cast<Tree::TREE_TYPE>(0 + (rand() % 5)));
        Tree* treeCopy = new Tree(*tree);
        spForest1->growUp(tree);
        spForest1->growUp(treeCopy);

        delete tree;
        delete treeCopy;
        tree = nullptr;
        treeCopy = nullptr;

        std::cout << std::left << std::setw(25) << "Number of trees in the first forest after original and copy addition : " << std::setw(25) << spForest1->getTreesNumber() << std::endl;
    }else{
        std::cerr << "Error : Forest class object is undefined!";
        std::cout << std::endl;
        exit(EXIT_FAILURE);
    }

    auto spForest2 = std::make_shared<Forest>();
    if(spForest2){
        spForest2->autoPlantForest(200);
        std::cout << std::left << std::setw(25) << "Number of trees in the second forest : " << std::setw(25) << spForest2->getTreesNumber() << std::endl;
    }else{
        std::cerr << "Error : Forest class object is undefined!";
        std::cout << std::endl;
        exit(EXIT_FAILURE);
    }

    std::shared_ptr<Forest> spForest3{};

    try {
        spForest3 = *spForest1 + spForest2;
    }
    catch (const std::invalid_argument& e)
    {
        std::cerr << e.what() << std::endl;
        exit(EXIT_FAILURE);
    }

    if(spForest3){
        std::cout << std::left << std::setw(25) << "Number of trees in the merged forest (first + second) : " << std::setw(25) << spForest3->getTreesNumber() << std::endl;
    }else{
        std::cerr << "Error : Forest class object is undefined!";
        std::cout << std::endl;
        exit(EXIT_FAILURE);
    }

    if(spForest2){
        spForest2->cutAll();
        std::cout << std::left << std::setw(25) << "The number of trees in the second forest after cutting down : " << std::setw(25) << spForest2->getTreesNumber() << std::endl;
    }else{
        std::cerr << "Error : Forest class object is undefined!";
        std::cout << std::endl;
        exit(EXIT_FAILURE);
    }    

    return 0;
}
