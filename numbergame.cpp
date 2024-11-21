#include "numbergame.h"
#include <ctime>

NumberGame::NumberGame(const std::string &player1, const std::string &player2, int winningNumber, unsigned stepsCounter) : m_player1(player1),
    m_player2(player2),
    m_winningNumber(winningNumber),
    m_stepsCounter(stepsCounter)
{}

void NumberGame::playingPlayer1()
{
    m_numberOfPlayer1 = m_numberOfPlayer1 >= 0 ? generateNegNum() : generatePosNum();
}

void NumberGame::playingPlayer2()
{
    m_numberOfPlayer2 = m_numberOfPlayer2 >= 0 ? generateNegNum() : generatePosNum();
}

void NumberGame::workingReferee(int number)
{
    m_score = m_score + number;
}

void NumberGame::decreaseStepCounter()
{
    if(m_stepsCounter > 0){
        m_stepsCounter--;
    }
}

int NumberGame::numberOfPlayer1() const
{
    return m_numberOfPlayer1;
}

int NumberGame::numberOfPlayer2() const
{
    return m_numberOfPlayer2;
}

int NumberGame::score() const
{
    return m_score;
}

unsigned NumberGame::stepsCounter() const
{
    return m_stepsCounter;
}

int NumberGame::winningNumber() const
{
    return m_winningNumber;
}

int NumberGame::generatePosNum()
{
    srand((unsigned) time(NULL));
    int random = 0 + (rand() % 6);
    return random;
}

int NumberGame::generateNegNum()
{
    srand((unsigned) time(NULL));
    int random = -5 + (rand() % 5);
    return random;
}
