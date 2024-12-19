#include "book.h"
#include "catalog.h"
#include <iostream>
#include <memory>
#include <regex>

int main(){
    auto upCatalog {std::make_unique<Catalog>("Amazon")};

    std::cout << "------------------------------------------------------" << std::endl;
    std::cout << "Testing the Book class copy constructor" << std::endl;
    std::cout << "------------------------------------------------------" << std::endl;

    std::unique_ptr<Book> upBookTest {std::move(upCatalog->getBook())};

    if(upBookTest){
        std::cout << "------------------------------------------------------" << std::endl;
        std::cout << "Book information" << std::endl;
        upBookTest->printInfo();
    }else{
        std::cerr << "Error : Book class object is undefined!";
        std::cout << std::endl;
        exit(EXIT_FAILURE);
    }

    auto upBookTestCopy {std::make_unique<Book>(*upBookTest)};

    if(upBookTestCopy){
        std::cout << "------------------------------------------------------" << std::endl;
        std::cout << "Book copy information" << std::endl;
        upBookTestCopy->printInfo();
    }else{
        std::cerr << "Error : Book class object is undefined!";
        std::cout << std::endl;
        exit(EXIT_FAILURE);
    }

    std::cout << "------------------------------------------------------" << std::endl;
    std::cout << "Testing the Catalog class API" << std::endl;    

    try {
        upCatalog->testCatalogFiltering();
    }
    catch (const std::invalid_argument& e)
    {
        std::cerr << e.what() << std::endl;
        exit(EXIT_FAILURE);
    }

    std::cout << "------------------------------------------------------" << std::endl;
    std::cout << "Size of catalog before clear : " << upCatalog->getCatalogSize() << std::endl;
    upCatalog->clearCatalog();
    std::cout << "------------------------------------------------------" << std::endl;
    std::cout << "Size of catalog after clear : " << upCatalog->getCatalogSize() << std::endl;

    return 0;
}
