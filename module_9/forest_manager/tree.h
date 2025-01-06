#ifndef TREE_H
#define TREE_H

#include <string>

///
/// \brief The Tree class for creating tree objects
///
class Tree
{
public:
    enum class TreeType {
        UNKNOWN = -1,
        PINE,
        OAK,
        MAPLE,
        BIRCH,
        ASPEN
    };

public:
    Tree(const TreeType treeType);
    Tree(const std::string& name, const TreeType treeType);
    Tree(const Tree& tree);

    ///
    /// \brief Prints the name and id of the tree
    ///
    void wind() const;

    ///
    /// \brief Getters
    /// \return
    ///
    size_t getId() const;
    std::string getName() const;

private:
    inline static size_t m_counter{};
    inline static std::string m_pineTreeNames[3] = {"Red Pine", "Austrian Pine", "Longleaf Pine"};
    inline static std::string m_oakTreeNames[3] = {"Black Oak", "Northern Red Oak", "Live Oak"};
    inline static std::string m_mapleTreeNames[3] = {"Red Maple", "Amur Maple", "Norway Maple"};
    inline static std::string m_birchTreeNames[3] = {"Silver Birch", "Dwarf Birch", "Himalayan Birch"};
    inline static std::string m_aspenTreeNames[3] = {"Golden Aspen", "European Aspen", "Trembling Aspen"};

    std::string generateName(const TreeType treeType) const;
    TreeType getTreeType() const;

    std::string m_name{"undefined"};
    TreeType m_treeType{TreeType::UNKNOWN};
    size_t m_id{};
};

#endif // TREE_H
