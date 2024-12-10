#include "sharedptrtest.h"

int main(){
    auto pSpt = std::make_unique<SharedPtrTest>();
    pSpt->runTest();
    return 0;    
}
