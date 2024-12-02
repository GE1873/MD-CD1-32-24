#include "vectorsorter.h"
#include <cstdlib>
#include <ctime>
#include <vector>
#include<iostream>

#include<algorithm>

VectorSorter::VectorSorter()
{

}

void VectorSorter::createAndPrintVector()
{
    std::cout << "******************************************************" << std::endl;
    std::cout << "Vector sorting" << std::endl;
    std::cout << "******************************************************" << std::endl;
    size_t size {10};
    std::vector<int> v {};
    int start {1};
    int end {100};
    std::srand(std::time(0));
    for (size_t i {}; i < size; ++i) {
        int randNum = start + rand() % (end - start + 1);
        v.push_back(randNum);
    }
    std::cout << "------------------------------------------------------" << std::endl;
    std::cout << "Vector before sorting : ";
    for (auto i : v) {
        std::cout << i << " ";
    }
    std::cout << std::endl;
    std::sort(v.begin(), v.end(), [](int a, int b) {
        return a < b;
    });
    std::cout << "------------------------------------------------------" << std::endl;
    std::cout << "Vector after sorting : ";
    for (auto i : v) {
        std::cout << i << " ";
    }
    std::cout << std::endl;
    std::cout << "------------------------------------------------------" << std::endl;
}
