#ifndef NUMBERGAME_H
#define NUMBERGAME_H

#include <iostream>

///
/// \brief Implementation of the number game
///
class NumberGame
{
public:
    ///
    /// \brief Constructor with default parameters
    ///
    NumberGame(const std::string &player1, const std::string &player2, int winningNumber, unsigned stepsCounter);

    ///
    /// \brief Generates a random number for player 1, alternating positive and negative
    ///
    void playPlayer1();

    ///
    /// \brief Generates a random number for player 1, alternating positive and negative
    ///
    void playPlayer2();

    ///
    /// \brief Calculates sum of numbers
    /// \param number - Randomly generated number for player 1 or 2
    ///
    void workReferee(int number);

    ///
    /// \brief Reduces the game step counter
    ///
    void decreaseStepCounter();

    ///
    /// \brief Getter for player 1 number
    /// \return
    ///
    int numberOfPlayer1() const;

    ///
    /// \brief Getter for player 1 number
    /// \return
    ///
    int numberOfPlayer2() const;

    ///
    /// \brief Getter for game score
    /// \return
    ///
    int score() const;

    ///
    /// \brief Getter for step counter
    /// \return
    ///
    unsigned stepsCounter() const;

    ///
    /// \brief Getter for winning number
    /// \return
    ///
    int winningNumber() const;

private:
    std::string m_player1;
    std::string m_player2;
    unsigned int m_winningNumber;    

    int m_numberOfPlayer1 {};
    int m_numberOfPlayer2 {};
    int m_score {};
    unsigned m_stepsCounter {};

    ///
    /// \brief Random number generator for positive numbers (and zero) (0 to 5)
    /// \return
    ///
    int generatePosNum();

    ///
    /// \brief Random number generator for negative numbers (-5 to -1)
    /// \return
    ///
    int generateNegNum();
};

#endif // NUMBERGAME_H
