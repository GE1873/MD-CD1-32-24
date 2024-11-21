#ifndef NUMBERGAME_H
#define NUMBERGAME_H

#include <iostream>

///
/// \brief Implementation of the number game
///
class NumberGame
{
public:
    NumberGame(const std::string &player1, const std::string &player2, int winningNumber, unsigned stepsCounter);

    NumberGame(std::string player1 = {"Biba"}, std::string player2 = {"Boba"}, int winningNumber = 50, unsigned stepsCounter = 100):
        m_player1(player1),
        m_player2(player2),
        m_winningNumber(winningNumber),
        m_stepsCounter(stepsCounter)
    {}

    void playingPlayer1();
    void playingPlayer2();
    void workingReferee(int number);
    void decreaseStepCounter();

    int numberOfPlayer1() const;
    int numberOfPlayer2() const;
    int score() const;
    unsigned stepsCounter() const;
    int winningNumber() const;

private:
    std::string m_player1;
    std::string m_player2;
    unsigned int m_winningNumber;    

    int m_numberOfPlayer1 {};
    int m_numberOfPlayer2 {};
    int m_score {};
    unsigned m_stepsCounter {};

    int generatePosNum();
    int generateNegNum();
};

#endif // NUMBERGAME_H
