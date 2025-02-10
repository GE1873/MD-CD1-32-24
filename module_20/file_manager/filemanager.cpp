#include "filemanager.h"
#include <filesystem>
#include <iostream>

bool FileManager::checkFolderExist()
{
    if ( !std::filesystem::exists( _folderName ) ) {
        std::cout << "The folder does not exist." << std::endl;
        return false;
    }
    else return true;
}

void FileManager::analizeFolderContent()
{
    for ( const auto& entry : std::filesystem::directory_iterator( _folderName ) ) {
        if ( entry.is_regular_file() ) {
            _filesCounter++;
            if ( entry.path().extension() == ".exe" ) {
                _exeFiles.push_back( entry.path().filename().string() );
            }
        } else if ( entry.is_directory() ) {
            _foldersCounter++;
        }
    }
}

void FileManager::printFolderContent()
{
    std::cout << "------------------------------------------------------" << std::endl;
    std::cout << "Number of files in the folder : " << _filesCounter << std::endl;
    std::cout << "Number of folders in the folder : " << _foldersCounter << std::endl;

    if ( !_exeFiles.empty() ) {
        std::cout << "Files with the .exe extension : " << std::endl;
        for ( const auto& file : _exeFiles ) {
            std::cout << file << std::endl;
        }
    } else {
        std::cout << "There are no files with the .exe extension in the folder." << std::endl;
    }
}

void FileManager::setFolderName()
{
    std::cout << "------------------------------------------------------" << std::endl;
    std::cout << "Please, enter a folder name : ";
    std::cin >> _folderName;
}
