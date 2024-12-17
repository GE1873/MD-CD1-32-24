#include "catalog.h"
#include <ctime>
#include <iomanip>
#include <iostream>
#include <regex>

Catalog::Catalog(const std::string& name) : m_name{name} {}

void Catalog::addToCatalog(const std::unique_ptr<Book> upBook)
{
    if(upBook){        
        std::string strSectionNum{};
        int sectionNum{};
        bool isSectionNumValid {};
        std::cout << "Please, enter the section of the book in the catalog : " << std::endl;
        std::cout << "1 - for Crime" << std::endl;
        std::cout << "2 - for Horror" << std::endl;
        std::cout << "3 - for Thriller" << std::endl;
        std::cout << "4 - for Fantasy" << std::endl;
        std::cout << "5 - for Historical" << std::endl;
        while(!isSectionNumValid){
            std::getline (std::cin, strSectionNum);
            if (regex_match (strSectionNum, std::regex("[1-5]"))){                
                Catalog::SECTION section = static_cast<Catalog::SECTION>(std::stoi(strSectionNum));
                BookRecord br{*upBook, section, getAdditionDateTime()};
                m_bookRecords.push_back(br);
                isSectionNumValid = true;
            } else {
                std::cerr << "Error : Incorrect ISBN entered!" << std::endl;
                std::cout << "Please, try to enter the ISBN again : ";
            }
        }

    }else{
        throw std::invalid_argument("book class object is undefined");
    }
}

size_t Catalog::getCatalogSize() const
{
    return m_bookRecords.size();
}

void Catalog::clearCatalog()
{
    m_bookRecords.clear();
}

void Catalog::printAdditionDateTime(const BookRecord& br) const
{
    char datetimeString[100];
    strftime(datetimeString, sizeof(char)*100, "%B %d, %Y, %H:%M:%S", &br.adt);
    std::cout << std::left << std::setw(30) << "Addition date and time : " << datetimeString << std::endl;
}

std::unique_ptr<Book> Catalog::getBook()
{
    std::string strTitle{};
    std::string strAuthor{};
    std::string strGenre{};
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

    std::cout << "Please, enter the genre of the book : ";
    std::getline (std::cin, strGenre);

    auto upBook {std::make_unique<Book>(strTitle, strAuthor, year, isbn, strGenre)};

    delete[] isbn;
    isbn = nullptr;

    return upBook;
}

void Catalog::testCatalogFiltering()
{
    std::string strTitle{};
    std::string strAuthor{};
    std::string strGenre{};
    std::string strYear{};
    int year{};
    std::string strIsbn13{};
    int isbnSize{17};
    char* isbn{};

    for(size_t i{}; i<5; ++i){
        isbn = new char [isbnSize];
        std::cout << "------------------------------------------------------" << std::endl;
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

        std::cout << "Please, enter the genre of the book : ";
        std::getline (std::cin, strGenre);

        auto upBook {std::make_unique<Book>(strTitle, strAuthor, year, isbn, strGenre)};

        delete[] isbn;
        isbn = nullptr;

        if(upBook){
            this->addToCatalog(std::move(upBook));
        }else{
            throw std::invalid_argument("catalog class object is undefined");
        }
    }

    std::cout << "------------------------------------------------------" << std::endl;
    std::cout << "* FILTERING *" << std::endl;
    std::cout << "------------------------------------------------------" << std::endl;
    std::cout << "Please, select a section to filter the catalog : " << std::endl;
    std::cout << "1 - for Crime" << std::endl;
    std::cout << "2 - for Horror" << std::endl;
    std::cout << "3 - for Thriller" << std::endl;
    std::cout << "4 - for Fantasy" << std::endl;
    std::cout << "5 - for Historical" << std::endl;
    bool isSectionNumValid {};
    std::string strSectionNum{};
    auto upFilteredBooksBySection {std::make_unique<std::vector<Catalog::BookRecord>>()};
    while(!isSectionNumValid){
        std::getline (std::cin, strSectionNum);
        if (regex_match (strSectionNum, std::regex("[1-5]"))){
            Catalog::SECTION section = static_cast<Catalog::SECTION>(std::stoi(strSectionNum));
            if(upFilteredBooksBySection){
                upFilteredBooksBySection = this->getBooksBySection(section);
            }else{
                throw std::invalid_argument("vector is undefined");
            }
            isSectionNumValid = true;
        } else {
            std::cerr << "Error : Incorrect ISBN entered!" << std::endl;
            std::cout << "Please, try to enter the ISBN again : ";
        }
    }
    std::cout << "------------------------------------------------------" << std::endl;
    if(upFilteredBooksBySection->size() > 0){
        for(const auto& br : *upFilteredBooksBySection){
            br.book.printInfo();
            this->printAdditionDateTime(br);
            std::cout << "------------------------------------------------------" << std::endl;
        }
    }else{
        std::cout << "Books not found" << std::endl;
    }

    std::cout << "Please, enter the string contained in the title : " << std::endl;
    std::getline (std::cin, strTitle);
    auto upFilteredBooksByTitle {std::make_unique<std::vector<Catalog::BookRecord>>()};
    if(upFilteredBooksByTitle){
        upFilteredBooksByTitle = this->getBooksByTitle(strTitle);
    }else{
        throw std::invalid_argument("vector is undefined");
    }
    std::cout << "------------------------------------------------------" << std::endl;
    if(upFilteredBooksByTitle->size() > 0){
        for(const auto& br : *upFilteredBooksByTitle){
            br.book.printInfo();
            this->printAdditionDateTime(br);
            std::cout << "------------------------------------------------------" << std::endl;
        }
    }else{
        std::cout << "Books not found" << std::endl;
    }

    std::cout << "Please, enter the string contained in the author : " << std::endl;
    std::getline (std::cin, strAuthor);
    auto upFilteredBooksByAuthor {std::make_unique<std::vector<Catalog::BookRecord>>()};
    if(upFilteredBooksByAuthor){
        upFilteredBooksByAuthor = this->getBooksByAuthor(strAuthor);
    }else{
        throw std::invalid_argument("vector is undefined");
    }
    std::cout << "------------------------------------------------------" << std::endl;
    if(upFilteredBooksByAuthor->size() > 0){
        for(const auto& br : *upFilteredBooksByAuthor){
            br.book.printInfo();
            this->printAdditionDateTime(br);
            std::cout << "------------------------------------------------------" << std::endl;
        }
    }else{
        std::cout << "Books not found" << std::endl;
    }

    bool isYearValid {};    
    std::cout << "Please, enter the year of the book in format XXXX : ";
    auto upFilteredBooksByYear {std::make_unique<std::vector<Catalog::BookRecord>>()};
    while(!isYearValid){
        std::getline (std::cin, strYear);
        if (regex_match (strYear, std::regex("[0-9]{4}"))){
            year = std::stoi(strYear);
            if(upFilteredBooksByYear){
                upFilteredBooksByYear = this->getBooksByYear(year);
            }else{
                throw std::invalid_argument("vector is undefined");
            }
            isYearValid = true;
        } else {
            std::cerr << "Error : Incorrect year entered!" << std::endl;
            std::cout << "Please, try to enter the year again : ";
        }
    }
    std::cout << "------------------------------------------------------" << std::endl;
    if(upFilteredBooksByYear->size() > 0){
        for(const auto& br : *upFilteredBooksByYear){
            br.book.printInfo();
            this->printAdditionDateTime(br);
            std::cout << "------------------------------------------------------" << std::endl;
        }
    }else{
        std::cout << "Books not found" << std::endl;
    }
}

tm Catalog::getAdditionDateTime() const
{
    time_t now = time(0);
    tm* ltm = localtime(&now);
    return *ltm;
}

std::unique_ptr<std::vector<Catalog::BookRecord>> Catalog::getBooksBySection(const SECTION section) const
{
    auto upBooks {std::make_unique<std::vector<Catalog::BookRecord>>()};
    for(const auto& br : m_bookRecords){
        if(br.section == section) upBooks->push_back(br);
    }
    return upBooks;
}

std::unique_ptr<std::vector<Catalog::BookRecord>> Catalog::getBooksByTitle(const std::string& title) const
{
    auto upBooks {std::make_unique<std::vector<Catalog::BookRecord>>()};
    for(const auto& br : m_bookRecords){
        if (br.book.title().find(title) != std::string::npos) upBooks->push_back(br);
    }
    return upBooks;
}

std::unique_ptr<std::vector<Catalog::BookRecord>> Catalog::getBooksByAuthor(const std::string& author) const
{
    auto upBooks {std::make_unique<std::vector<Catalog::BookRecord>>()};
    for(const auto& br : m_bookRecords){
        if (br.book.author().find(author) != std::string::npos) upBooks->push_back(br);
    }
    return upBooks;
}

std::unique_ptr<std::vector<Catalog::BookRecord>> Catalog::getBooksByYear(int year) const
{
    auto upBooks {std::make_unique<std::vector<Catalog::BookRecord>>()};
    for(const auto& br : m_bookRecords){
        if (br.book.year() == year) upBooks->push_back(br);
    }
    return upBooks;
}
