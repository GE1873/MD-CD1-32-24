#ifndef FOREST_H
#define FOREST_H

#include "tree.h"
#include <memory>
#include <vector>

class Forest
{
public:
    Forest() = default;
    Forest(const std::vector<Tree>& trees);

    void growUp(const Tree& tree);
    void cutAll();
    void autoPlantForest();
    size_t getTreesNumber() const;
    std::vector<Tree> trees() const;

private:
    std::vector<Tree> m_trees{};
};

#endif // FOREST_H
