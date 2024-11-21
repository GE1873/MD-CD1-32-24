#ifndef MULTIPLICATIONTABLE_H
#define MULTIPLICATIONTABLE_H

///
/// \brief Creating multiplication tables for different loops
///
class MultiplicationTable
{
public:
    MultiplicationTable();

    ///
    /// \brief Creating a multiplication table using a FOR loop
    ///
    void mtUsingFor() const;

    ///
    /// \brief Creating a multiplication table using a WHILE loop
    ///
    void mtUsingWhile() const;

    ///
    /// \brief Creating a multiplication table using a DO-WHILE loop
    ///
    void mtUsingDoWhile() const;
};

#endif // MULTIPLICATIONTABLE_H
