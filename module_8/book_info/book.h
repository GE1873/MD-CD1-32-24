#ifndef BOOK_H
#define BOOK_H

#include <memory>
#include <string>

///
/// \brief Book class for describing basic information about a book
///
class Book
{
public:
    Book(const std::string& title,
         const std::string& author,
         int year,
         const char* const isbn,
         const std::string& genre);
    Book(const Book& book);
    ~Book();

    ///
    /// \brief Prints information about the book
    ///
    void printInfo() const;

    ///
    /// \brief Getters
    ///
    std::string title() const;
    std::string author() const;
    int year() const;
    char* isbn() const;
    std::string genre() const;

private:
    char* getIsbnCopy(const char* const isbn) const;

    std::string m_title{};
    std::string m_author{};
    int m_year{};
    char* m_isbn{};
    std::string m_genre{};
    static const int m_isbnSize{17};
};

#endif // BOOK_H
