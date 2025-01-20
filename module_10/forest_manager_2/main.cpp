#include "forests/coniferousforest.h"
#include "forests/deciduousforest.h"
#include "trees/birch.h"
#include "trees/oak.h"
#include "trees/cedar.h"
#include "trees/pine.h"

#include <ctime>
#include <iostream>
#include <iomanip>
#include <memory>

int main(){
    std::srand( std::time( 0 ) );

    auto coniferousForest = new ConiferousForest();
    auto deciduousForest = new DeciduousForest();

    auto birchTree1 = new Birch();
    auto birchTree1Copy = new Birch( *birchTree1 );
    auto birchTree2 = new Birch();

    auto oakTree1 = new Oak();
    auto oakTree1Copy = new Oak( *oakTree1 );
    auto oakTree2 = new Oak();    

    auto pineTree1 = new Pine();
    auto pineTree1Copy = new Pine( *pineTree1 );
    auto pineTree2 = new Pine();    

    auto cedarTree1 = new Cedar();
    auto cedarTree1Copy = new Cedar( *cedarTree1 );
    auto cedarTree2 = new Cedar();

    if( coniferousForest ){
        std::cout << "------------------------------------------------------" << std::endl;
        try{
            coniferousForest->growUp( birchTree1 );
            coniferousForest->growUp( birchTree1Copy );
            coniferousForest->growUp( birchTree2 );

            coniferousForest->growUp( pineTree1 );
            coniferousForest->growUp( pineTree1Copy );
            coniferousForest->growUp( pineTree2 );
            coniferousForest->growUp( cedarTree1 );
            coniferousForest->growUp( cedarTree1Copy );
            coniferousForest->growUp( cedarTree2 );
        }
        catch ( const std::invalid_argument& e ){
            std::cerr << e.what() << std::endl;
        }
        coniferousForest->wind();
        if( coniferousForest->isContainTreeType( TreeNamesGenerator::TreeType::CEDAR ) ) {
            std::cout << "------------------------------------------------------" << std::endl;
            std::cout << std::left << std::setw( 25 ) << "Number of cedars in the coniferous forest : " << std::setw( 25 ) << Cedar::getNumOfTrees() << std::endl;
        }
        if( coniferousForest->isContainTreeType( TreeNamesGenerator::TreeType::PINE ) ) {
            std::cout << "------------------------------------------------------" << std::endl;
            std::cout << std::left << std::setw( 25 ) << "Number of pines in the coniferous forest : " << std::setw( 25 ) << Pine::getNumOfTrees() << std::endl;
        }

    } else{
        std::cerr << "Error : Forest class object is undefined!";
        std::cout << std::endl;
    }

    if( deciduousForest ){
        std::cout << "------------------------------------------------------" << std::endl;
        try{
            deciduousForest->growUp( pineTree1 );
            deciduousForest->growUp( pineTree1Copy );
            deciduousForest->growUp( pineTree2 );

            deciduousForest->growUp( birchTree1 );
            deciduousForest->growUp( birchTree1Copy );
            deciduousForest->growUp( birchTree2 );
            deciduousForest->growUp( oakTree1 );
            deciduousForest->growUp( oakTree1Copy );
            deciduousForest->growUp( oakTree2 );
        }
        catch ( const std::invalid_argument& e ){
            std::cerr << e.what() << std::endl;
        }
        deciduousForest->wind();
        if( deciduousForest->isContainTreeType( TreeNamesGenerator::TreeType::BIRCH ) ) {
            std::cout << "------------------------------------------------------" << std::endl;
            std::cout << std::left << std::setw( 25 ) << "Number of birches in the deciduous forest : " << std::setw( 25 ) << Birch::getNumOfTrees() << std::endl;
        }
        if( deciduousForest->isContainTreeType( TreeNamesGenerator::TreeType::OAK ) ) {
            std::cout << "------------------------------------------------------" << std::endl;
            std::cout << std::left << std::setw( 25 ) << "Number of oaks in the deciduous forest : " << std::setw( 25 ) << Oak::getNumOfTrees() << std::endl;
        }

    } else{
        std::cerr << "Error : Forest class object is undefined!";
        std::cout << std::endl;
    }

    delete coniferousForest;
    delete deciduousForest;

    return 0;
}
