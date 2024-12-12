#ifndef BOOK_H
#define BOOK_H

#include <memory>
#include <string>

class Book
{
public:
    Book(const std::string& title, const std::string& author, int year, char* isbn);
    Book(const Book& book);
    ~Book();

    void printInfo() const;

    std::string title() const;
    std::string author() const;
    int year() const;
    char* isbn() const;

private:
    char* getIsbnCopy(char* isbn);

    std::string m_title{};
    std::string m_author{};
    int m_year{};
    char* m_isbn{};
    static constexpr int m_isbnSize{17};
};

#endif // BOOK_H
