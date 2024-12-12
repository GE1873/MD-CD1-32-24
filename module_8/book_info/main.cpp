#include "book.h"
#include <iostream>
#include <memory>
#include <regex>

int main(){

    std::string strTitle{};
    std::string strAuthor{};
    std::string strYear{};
    int year{};
    std::string strIsbn13{};

    int isbnSize{17};
    char* isbn {new char [isbnSize]};

    std::cout << "Please, enter the title of the book : ";
    std::getline (std::cin, strTitle);

    std::cout << "Please, enter the author of the book : ";
    std::getline (std::cin, strAuthor);

    bool isYearValid {};
    std::cout << "Please, enter the year of the book in format XXXX : ";
    while(!isYearValid){
        std::getline (std::cin, strYear);
        if (regex_match (strYear, std::regex("[0-9]{4}"))){
            year = std::stoi(strYear);
            isYearValid = true;
        } else {
            std::cerr << "Error : Incorrect year entered!" << std::endl;
            std::cout << "Please, try to enter the year again : ";
        }
    }

    bool isIsbnValid {};

    std::cout << "Please, enter the ISBN of the book in format XXX-X-XXX-XXXXX-X : ";
    while(!isIsbnValid){
        std::getline (std::cin, strIsbn13);
        if (regex_match (strIsbn13, std::regex("[0-9]{3}-[0-9]{1}-[0-9]{3}-[0-9]{5}-[0-9]{1}"))){
            memcpy(isbn, strIsbn13.c_str(), sizeof(char) * isbnSize);
            isIsbnValid = true;
        } else {
            std::cerr << "Error : Incorrect ISBN entered!" << std::endl;
            std::cout << "Please, try to enter the ISBN again : ";
        }
    }

    auto upBook {std::make_unique<Book>(strTitle, strAuthor, year, isbn)};

    delete[] isbn;
    isbn = nullptr;

    if(upBook){
        std::cout << "Book info : " << std::endl;
        upBook->printInfo();
    }else{
        std::cerr << "Error : Book class object is undefined!";
        std::cout << std::endl;
        exit(EXIT_FAILURE);
    }

    auto upBookCopy {std::make_unique<Book>(*upBook)};

    if(upBookCopy){
        std::cout << "Book copy info : " << std::endl;
        upBookCopy->printInfo();
    }else{
        std::cerr << "Error : Book class object is undefined!";
        std::cout << std::endl;
        exit(EXIT_FAILURE);
    }

    return 0;
}

