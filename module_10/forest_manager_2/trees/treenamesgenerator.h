#ifndef TREESGENERATOR_H
#define TREESGENERATOR_H

#include <string>

///
/// \brief TreeNamesGenerator class for generating tree names
///
class TreeNamesGenerator
{
public:
    enum class TreeType {
        UNKNOWN = -1,
        PINE,
        CEDAR,
        OAK,
        BIRCH
    };

    enum class TreeCategory {
        UNKNOWN = -1,
        CONIFEROUS,
        DECIDUOUS,
    };

    ///
    /// \brief Generates a name for the tree
    /// \param treeType
    /// \return
    ///
    static std::string generateName( const TreeType treeType );

    ///
    /// \brief Gets a human-readable name for the tree
    /// \param treeType
    /// \return
    ///
    static std::string getTypeName( const TreeType treeType );

private:
    inline static std::string _pineTreeNames[3] = { "Red Pine", "Austrian Pine", "Longleaf Pine" };
    inline static std::string _oakTreeNames[3] = { "Black Oak", "Northern Red Oak", "Live Oak" };
    inline static std::string _cedarTreeNames[3] = { "Alaska cedar", "Lebanon cedar", "Atlas Cedar" };
    inline static std::string _birchTreeNames[3] = { "Silver Birch", "Dwarf Birch", "Himalayan Birch" };
};

#endif // TREESGENERATOR_H
