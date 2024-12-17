#ifndef CATALOG_H
#define CATALOG_H

#include "book.h"
#include <string>
#include <vector>

///
/// \brief Catalog class for sectioning and filtering books
///
class Catalog
{
private:
    enum class SECTION {
        UNKNOWN = -1,
        CRIME = 1,
        HORROR,
        THRILLER,
        FANTASY,
        HISTORICAL
    };

    struct BookRecord{
        Book book;
        SECTION section;
        tm adt;
    };

public:
    Catalog(const std::string& name);

    ///
    /// \brief Adds a book to the catalog
    /// \param upBook
    ///
    void addToCatalog(const std::unique_ptr<Book> upBook);

    ///
    /// \brief Gets the catalog size
    /// \return
    ///
    size_t getCatalogSize() const;


    ///
    /// \brief Clears the catalog
    ///
    void clearCatalog();

    ///
    /// \brief Prints the date and time the book was added
    /// \param br
    ///
    void printAdditionDateTime(const BookRecord& br) const;

    ///
    /// \brief Creates a book object and populates it with information
    /// \return
    ///
    std::unique_ptr<Book> getBook();

    ///
    /// \brief Tests the API of the Catalog class
    ///
    void testCatalogFiltering();

    ///
    /// \brief Filters the catalog by section
    /// \param section
    /// \return
    ///
    std::unique_ptr<std::vector<Catalog::BookRecord>> getBooksBySection(const SECTION section) const;

    ///
    /// \brief Filters the catalog by title
    /// \param title
    /// \return
    ///
    std::unique_ptr<std::vector<Catalog::BookRecord>> getBooksByTitle(const std::string& title) const;

    ///
    /// \brief Filters the catalog by author
    /// \param author
    /// \return
    ///
    std::unique_ptr<std::vector<Catalog::BookRecord>> getBooksByAuthor(const std::string& author) const;

    ///
    /// \brief Filters the catalog by year
    /// \param year
    /// \return
    ///
    std::unique_ptr<std::vector<Catalog::BookRecord>> getBooksByYear(int year) const;

private:
    tm getAdditionDateTime() const;

    std::string m_name{};
    std::vector<BookRecord> m_bookRecords{};
};

#endif // CATALOG_H
