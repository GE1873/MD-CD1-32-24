#ifndef TARIFF_H
#define TARIFF_H

///
/// \brief The Tariff base class
///
class Tariff
{
protected:
    Tariff() = default;

    void setDistanceRate( float distanceRate );
    void setWeightRate( float weightRate );
    void setTimeRate( float timeRate );
    float getDistanceRate() const;
    float getWeightRate() const;
    float getTimeRate() const;

    float _distanceRate{};
    float _weightRate{};
    float _timeRate{};
};

#endif // TARIFF_H
