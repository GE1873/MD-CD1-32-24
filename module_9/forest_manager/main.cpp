#include "forest.h"
//#include "tree.h"

#include <ctime>
#include <iostream>
#include <iomanip>
#include <memory>

std::shared_ptr<Forest> operator+(const std::shared_ptr<Forest> forest1, const std::shared_ptr<Forest> forest2)
{
    if(forest1 && forest2){
        std::vector<Tree> newForestTrees{};

        std::vector<Tree> t1 = forest1->trees();
        std::vector<Tree> t2 = forest2->trees();

        newForestTrees.reserve(t1.size() + t2.size());
        newForestTrees.insert(newForestTrees.end(), t1.begin(), t1.end());
        newForestTrees.insert(newForestTrees.end(), t2.begin(), t2.end());
        return std::make_shared<Forest>(newForestTrees);
    }else{
        throw std::invalid_argument("forest class object is undefined");
    }
}

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

    std::shared_ptr<Forest> upForest3 = upForest1 + upForest2;

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
