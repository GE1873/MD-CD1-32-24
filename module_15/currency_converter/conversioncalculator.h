#ifndef CONVERSIONCALCULATOR_H
#define CONVERSIONCALCULATOR_H

#include <QObject>

///
/// \brief The ConversionCalculator class for performing currency conversion
///
class ConversionCalculator : public QObject
{
    Q_OBJECT
public:
    explicit ConversionCalculator(QObject *parent = nullptr);

    ///
    /// \brief Calculates BYN currency value
    ///
    void calculateByn();

    ///
    /// \brief Calculates others currency values
    ///
    void calculateOther();

    ///
    /// \brief Getters and setters
    ///
    qreal getCurrencyRate() const;
    void setCurrencyRate(qreal newCurrencyRate);
    quint32 getCurrencyScale() const;
    void setCurrencyScale(quint32 newCurrencyScale);
    qreal getBynValue() const;
    void setBynValue(qreal newBynValue);
    qreal getOtherValue() const;
    void setOtherValue(qreal newOtherValue);

private:
    qreal _currencyRate{};
    qreal _currencyScale{1};
    qreal _bynValue{};
    qreal _otherValue{};
};

#endif // CONVERSIONCALCULATOR_H
