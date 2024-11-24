#include "factorialcalculation.h"
#include "systeminfo.h"

#include "multiplicationtable.h"
#include "numbergame.h"

#include <ctime>
#include <iostream>

int main()
{
    return 0;

    ///
    /// \brief Module 3 : Made creation of multiplication tables and number game
    ///
    MultiplicationTable mt;

    mt.createMtUsingFor();
    mt.createMtUsingWhile();
    mt.createMtUsingDoWhile();

    std::cout << std::endl;
    std::cout << "********************************************" << std::endl;
    std::cout << "********** Now, let's play a game! *********" << std::endl;
    std::cout << "********************************************" << std::endl;

    std::srand(std::time(0));

    std::string player1 {};
    std::string player2 {};

    std::cout << std::endl;
    std::cout << "Please, enter the first player's name : ";
    std::getline (std::cin, player1);

    std::cout << "Please, enter the second player's name : ";
    std::getline (std::cin, player2);

    NumberGame ng(player1, player2, 10, 25);

    while(true){
        std::cout << std::endl;
        std::cout << "Player " + player1 + " should choose the number (press \"Enter\")";
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        ng.playPlayer1();
        std::cout << "Player " + player1 + " has chosen a number : " + std::to_string(ng.numberOfPlayer1()) << std::endl;
        ng.workReferee(ng.numberOfPlayer1());
        std::cout << "Total score in the game is : " + std::to_string(ng.score()) << std::endl;
        if(ng.score() > ng.winningNumber()) {
            std::cout << std::endl;
            std::cout << "Player " + player1 + " won!" << std::endl;
            std::cout << "Game over!" << std::endl;
            break;
        }

        std::cout << std::endl;
        std::cout << "Player " + player2 + " should choose the number (press \"Enter\")";
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        ng.playPlayer2();
        std::cout << "Player " + player2 + " has chosen a number : " + std::to_string(ng.numberOfPlayer2()) << std::endl;
        ng.workReferee(ng.numberOfPlayer2());
        std::cout << "Total score in the game is : " + std::to_string(ng.score()) << std::endl;
        if(ng.score() > ng.winningNumber()) {
            std::cout << std::endl;
            std::cout << "Player " + player2 + " won!" << std::endl;
            std::cout << "Game over!" << std::endl;
            break;
        }

        ng.decreaseStepCounter();
        if(ng.stepsCounter() > 0){
            std::cout << std::endl;
            std::cout << std::to_string(ng.stepsCounter()) + " steps left until the end of the game" << std::endl;
            std::cout << std::endl;
            std::cout << "********************************************" << std::endl;
            std::cout << "Next game round"<< std::endl;
            std::cout << "********************************************" << std::endl;
        } else {
            std::cout << std::endl;
            std::cout << "The available number of steps is over!" << std::endl;
            std::cout << "Game result - draw!" << std::endl;
            std::cout << "Please, start the new game" << std::endl;
            break;
        }
    }
    ///
    ///

    ///
    /// \brief Module 2 : Calculation factorial of number 5 and getting system information
    ///
    FactorialCalculation fc;
    SystemInfo si;

    std::cout << "********************************************************************************" << std::endl;
    fc.calculateFactorial();
    std::cout << "********************************************************************************" << std::endl;
    si.getOSInfo();
    std::cout << "********************************************************************************" << std::endl;
    si.getCompilerInfo();
    std::cout << "********************************************************************************" << std::endl;
    ///
    ///
}
