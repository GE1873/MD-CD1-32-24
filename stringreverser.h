#ifndef STRINGREVERSER_H
#define STRINGREVERSER_H

///
/// \brief Reverses the entered string
///
class StringReverser
{
public:
    StringReverser();

    ///
    /// \brief Reverses and prints the entered string
    ///
    void reverseAndPrintEnteredString();

private:
    void reverseString(char* str);
};

#endif // STRINGREVERSER_H
