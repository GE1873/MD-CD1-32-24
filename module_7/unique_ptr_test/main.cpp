#include "uniqueptrtest.h"

int main(){
    auto pUpt = std::make_unique<UniquePtrTest>();
    pUpt->runTest();
    return 0;    
}
