#include "filemanager.h"

int main(){

    FileManager fm;

    fm.setFolderName();

    if ( fm.checkFolderExist() ) {
        fm.analizeFolderContent();
        fm.printFolderContent();
    }
    
    return 0;
}
