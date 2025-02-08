#include "conversioncalculator.h"

ConversionCalculator::ConversionCalculator(QObject *parent)
    : QObject{parent}
{
    
}

void ConversionCalculator::calculateByn()
{
    _bynValue = _otherValue * (_currencyRate / _currencyScale);
}

void ConversionCalculator::calculateOther()
{
    if(_bynValue == 0) {
        _otherValue = 0;
    } else _otherValue = _bynValue / (_currencyRate / _currencyScale);
}

qreal ConversionCalculator::getCurrencyRate() const
{
    return _currencyRate;
}

void ConversionCalculator::setCurrencyRate(qreal newCurrencyRate)
{
    _currencyRate = newCurrencyRate;
}

quint32 ConversionCalculator::getCurrencyScale() const
{
    return _currencyScale;
}

void ConversionCalculator::setCurrencyScale(quint32 newCurrencyScale)
{
    _currencyScale = newCurrencyScale;
}

qreal ConversionCalculator::getBynValue() const
{
    return _bynValue;
}

void ConversionCalculator::setBynValue(qreal newBynValue)
{
    _bynValue = newBynValue;
}

qreal ConversionCalculator::getOtherValue() const
{
    return _otherValue;
}

void ConversionCalculator::setOtherValue(qreal newOtherValue)
{
    _otherValue = newOtherValue;
}
