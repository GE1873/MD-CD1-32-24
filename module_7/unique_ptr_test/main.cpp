#include "uniqueptrtest.h"

int main(){
    UniquePtrTest upt;
    upt.createArray();
    upt.printArray(upt.getUniquePtr());
    return 0;    
}
