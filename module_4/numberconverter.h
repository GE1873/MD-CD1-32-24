#ifndef NUMBERCONVERTER_H
#define NUMBERCONVERTER_H

#include <string>

///
/// \brief Checking and converting number
///
class NumberConverter
{
public:
    enum class NUMBER_STATE {
        UNKNOWN = -1,
        EVEN_AND_POS = 100,
        ODD_OR_NEG = 200
    };

private:
        struct OperationResult {
        int convertedNum;
        NUMBER_STATE numState;
    };

    public:
        NumberConverter();

        ///
        /// \brief Checking number
        /// \param integer number
        /// \return structure OperationResult
        ///
        OperationResult checkNumber(int num);

        ///
        /// \brief Convert enumiration to string
        /// \param enumiration NUMBER_STATE
        /// \return string corresponding to the enumeration
        ///
        std::string convertEnum(NUMBER_STATE numState);
};

#endif // NUMBERCONVERTER_H
