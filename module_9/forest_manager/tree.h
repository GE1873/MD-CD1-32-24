#ifndef TREE_H
#define TREE_H

#include <string>

class Tree
{
public:
    enum class TREE_TYPE {
        UNKNOWN = -1,
        PINE,
        OAK,
        MAPLE,
        BIRCH,
        ASPEN
    };

public:
    Tree(const TREE_TYPE type);
    Tree(const std::string& name, const TREE_TYPE type);
    Tree(const Tree& tree);

    void wind() const;
    size_t getId() const;
    std::string getName() const;

private:
    static std::string pineTreeNames[3];
    static std::string oakTreeNames[3];
    static std::string mapleTreeNames[3];
    static std::string birchTreeNames[3];
    static std::string aspenTreeNames[3];

    std::string generateName(const TREE_TYPE type) const;
    TREE_TYPE getType() const;

    static size_t counter;
    std::string m_name{};
    TREE_TYPE m_type{};
    size_t m_id{counter++ + 1};
};

#endif // TREE_H
