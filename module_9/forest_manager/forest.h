#ifndef FOREST_H
#define FOREST_H

#include "tree.h"
#include <vector>

class Forest
{
public:
    Forest() = default;
    Forest(std::vector<Tree> trees);

    size_t getTreesNumber();
    void growUp(const Tree& tree);
    void cutAll();
    void autoPlantForest();
    std::vector<Tree> trees() const;

private:
    std::vector<Tree> m_trees{};
};

#endif // FOREST_H
