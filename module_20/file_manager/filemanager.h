#ifndef FILEMANAGER_H
#define FILEMANAGER_H

#include <string>
#include <vector>

class FileManager
{
public:
    FileManager() = default;

    bool checkFolderExist();

    void analizeFolderContent();

    void printFolderContent();

    void setFolderName();

private:
    std::string _folderName{};
    int _filesCounter{};
    int _foldersCounter{};
    std::vector<std::string> _exeFiles;
};

#endif // FILEMANAGER_H
