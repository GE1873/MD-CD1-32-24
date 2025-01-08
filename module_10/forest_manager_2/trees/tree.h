#ifndef TREE_H
#define TREE_H

#include <string>
#include "treenamesgenerator.h"

///
/// \brief The Tree abstract class
///
class Tree
{
public:
    explicit Tree( std::string name, TreeNamesGenerator::TreeType treeType, TreeNamesGenerator::TreeCategory treeCategory );
    virtual ~Tree() = default;

    ///
    /// \brief Prints the id, type and name of the tree
    ///
    virtual void wind() const = 0;

    ///
    /// \brief Gets tree category
    /// \return
    ///
    TreeNamesGenerator::TreeCategory getTreeCategory() const;

    ///
    /// \brief Gets tree type
    /// \return
    ///
    TreeNamesGenerator::TreeType getTreeType() const;

protected:        
    std::string getName() const;    
    size_t getId() const;

    std::string _name{ "undefined" };
    size_t _id{};
    TreeNamesGenerator::TreeType _treeType{ TreeNamesGenerator::TreeType::UNKNOWN };
    TreeNamesGenerator::TreeCategory _treeCategory{ TreeNamesGenerator::TreeCategory::UNKNOWN };
};

#endif // TREE_H
