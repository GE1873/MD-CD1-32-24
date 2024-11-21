#ifndef NUMBERGAME_H
#define NUMBERGAME_H

#include <iostream>

///
/// \brief Implementation of the number game
///
class NumberGame
{
public:
    NumberGame(std::string player1, std::string player2): m_player1(player1), m_player2(player2){}

    int playingPlayer1();
    int playingPlayer2();
    int workingReferee();

    int numberOfPlayer1() const;
    int numberOfPlayer2() const;
    int score() const;

private:
    std::string m_player1;
    std::string m_player2;

    int m_numberOfPlayer1 {};
    int m_numberOfPlayer2 {};
    int m_score {};
};

#endif // NUMBERGAME_H
