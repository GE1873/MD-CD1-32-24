#include "book.h"

#include <iomanip>
#include <iostream>

Book::Book(const std::string &title,
           const std::string &author,
           int year,
           const char* const isbn,
           const std::string &genre):
    m_title(title),
    m_author(author),
    m_year(year),
    m_isbn(getIsbnCopy(isbn)),
    m_genre(genre)
{}

Book::Book(const Book& book):
    m_title(book.title()),
    m_author(book.author()),
    m_year(book.year()),
    m_isbn(getIsbnCopy(book.isbn())),
    m_genre(book.genre())
{}

Book::~Book()
{
    delete[] m_isbn;
    m_isbn = nullptr;
}

void Book::printInfo() const
{    
    std::cout << std::left << std::setw(30) << "Title : " << m_title << std::endl;
    std::cout << std::left << std::setw(30) << "Author : " << m_author << std::endl;
    std::cout << std::left << std::setw(30) << "Year : " << m_year << std::endl;
    std::cout << std::left << std::setw(30) << "ISBN : ";
    for(size_t i {}; i < m_isbnSize; ++i){
        std::cout << *(m_isbn + i);
    }
    std::cout << std::endl;
    std::cout << std::left << std::setw(30) << "Genre : " << m_genre << std::endl;
}

std::string Book::title() const
{
    return m_title;
}

std::string Book::author() const
{
    return m_author;
}

int Book::year() const
{
    return m_year;
}

char* Book::isbn() const
{
    return m_isbn;
}

char* Book::getIsbnCopy(const char* const isbn) const
{
    char* newIsbn = new char [m_isbnSize];
    memcpy(newIsbn, isbn, sizeof(char) * m_isbnSize);
    return newIsbn;
}

std::string Book::genre() const
{
    return m_genre;
}
