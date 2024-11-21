//#include "factorialcalculation.h"
//#include "systeminfo.h"

#include "multiplicationtable.h"
#include "numbergame.h"
#include <iostream>

int main()
{
    //    FactorialCalculation fc;
    //    SystemInfo si;

    //    std::cout << "********************************************************************************" << std::endl;
    //    fc.calculateFactorial();
    //    std::cout << "********************************************************************************" << std::endl;
    //    si.getOSInfo();
    //    std::cout << "********************************************************************************" << std::endl;
    //    si.getCompilerInfo();
    //    std::cout << "********************************************************************************" << std::endl;

    MultiplicationTable mt;

    mt.mtUsingFor();
    mt.mtUsingWhile();
    mt.mtUsingDoWhile();

    std::cout << "********** Let's play a game! *********" << std::endl;

    std::string player1 {};
    std::string player2 {};

    std::cout << "Please, enter the first player's name : ";
    std::getline (std::cin, player1);

    std::cout << "Please, enter the second player's name : ";
    std::getline (std::cin, player2);

    NumberGame ng(player1, player2);

    while(true){
        std::cout << "Player " + player1 + " should choose the number (press \"Enter\")";
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        ng.playingPlayer1();
        std::cout << "Player " + player1 + " has chosen a number : " + std::to_string(ng.numberOfPlayer1()) << std::endl;
        ng.workingReferee();
        std::cout << "Total score in the game is : " + std::to_string(ng.score()) << std::endl;
        if(ng.score() > 50) {
            std::cout << "Player " + player1 + " won!" << std::endl;
            break;
        }

        std::cout << "Player " + player2 + " should choose the number (press \"Enter\")";
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        ng.playingPlayer2();
        std::cout << "Player " + player2 + " has chosen a number : " + std::to_string(ng.numberOfPlayer2()) << std::endl;
        ng.workingReferee();
        std::cout << "Total score in the game is : " + std::to_string(ng.score()) << std::endl;
        if(ng.score() > 50) {
            std::cout << "Player " + player1 + " won!" << std::endl;
            break;
        }
    }
    std::cout << "Game over!" << std::endl;


    return 0;
}
