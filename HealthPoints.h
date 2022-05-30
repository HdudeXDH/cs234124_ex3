#include <fstream>
#include <iostream>

#ifndef EX3_HEALTHPOINTS_H
#define EX3_HEALTHPOINTS_H

using std::ifstream;
using std::ofstream;

//healthPoint object for Mtmchkin
class HealthPoints {
public:
    HealthPoints(const int hp=HP_DEFAULT);
    HealthPoints(const HealthPoints &hp_instance)= default;
    ~HealthPoints()= default;
    HealthPoints &operator=(const HealthPoints& hp)= default;
    HealthPoints &operator-=(const int points);
    HealthPoints &operator+=(const int points);
    class InvalidArgument {};
    explicit operator int() const;

private:
    static const int HP_DEFAULT = 100;
    int m_points;
    int m_maxHp;
    friend std::ostream& operator<<(std::ostream& os, const HealthPoints& r);
    friend bool operator==(const HealthPoints& hp1, const HealthPoints& hp2);
    friend bool operator<(const HealthPoints& hp1, const HealthPoints& hp2);
};

HealthPoints operator-(const int points, const HealthPoints& hp1);
HealthPoints operator-(const HealthPoints& hp1, const int points);
HealthPoints operator+(const int points, const HealthPoints& hp1);
HealthPoints operator+(const HealthPoints& hp1, const int points);

bool operator!=(const HealthPoints& hp1, const HealthPoints& hp2);
bool operator>=(const HealthPoints& hp1, const HealthPoints& hp2);
bool operator>(const HealthPoints& hp1, const HealthPoints& hp2);
bool operator<=(const HealthPoints& hp1, const HealthPoints& hp2);

#endif //EX3_HEALTHPOINTS_H
