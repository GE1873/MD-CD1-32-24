#ifndef FILEMANAGER_H
#define FILEMANAGER_H

#include <string>
#include <vector>

///
/// \brief The FileManager class for checking folder contents
///
class FileManager
{
public:
    FileManager() = default;

    ///
    /// \brief Checks if a folder exist
    /// \return
    ///
    bool checkFolderExist();

    ///
    /// \brief Analyzes the contents of a folder
    ///
    void analizeFolderContent();

    ///
    /// \brief Prints the contents of a folder
    ///
    void printFolderContent();

    ///
    /// \brief Specifies the name of the folder to analyze
    ///
    void setFolderName();

private:
    std::string _folderName{};
    int _filesCounter{};
    int _foldersCounter{};
    std::vector<std::string> _exeFiles{};
};

#endif // FILEMANAGER_H
