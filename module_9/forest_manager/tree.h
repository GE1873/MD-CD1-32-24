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
    inline static size_t m_counter{};
    inline static std::string pineTreeNames[3] = {"Red Pine", "Austrian Pine", "Longleaf Pine"};
    inline static std::string oakTreeNames[3] = {"Black Oak", "Northern Red Oak", "Live Oak"};
    inline static std::string mapleTreeNames[3] = {"Red Maple", "Amur Maple", "Norway Maple"};
    inline static std::string birchTreeNames[3] = {"Silver Birch", "Dwarf Birch", "Himalayan Birch"};
    inline static std::string aspenTreeNames[3] = {"Golden Aspen", "European Aspen", "Trembling Aspen"};

    std::string generateName(const TREE_TYPE type) const;
    TREE_TYPE getType() const;

    std::string m_name{"undefined"};
    TREE_TYPE m_type{TREE_TYPE::UNKNOWN};
    size_t m_id{m_counter++ + 1};
};

#endif // TREE_H
