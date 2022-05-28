//
// Created by User on 5/27/2022.
//
#include <fstream>
using std::ifstream;
using std::ofstream;

#ifndef EX3_HEALTHPOINTS_H
#define EX3_HEALTHPOINTS_H

static const int HP_DEFAULT = 100;
// todo: validate negative values
class HealthPoints {
    int points;
    int maxHp;
    friend std::ostream& operator<<(std::ostream& os, const HealthPoints& r);
    friend bool operator==(const HealthPoints&, const HealthPoints&);
    friend bool operator<(const HealthPoints&, const HealthPoints&);

public:
    HealthPoints(const int hp=HP_DEFAULT);
    HealthPoints(const HealthPoints &hp_instance)= default;
    ~HealthPoints()= default;
    HealthPoints &operator=(const HealthPoints &)= default;
    explicit operator int() const; //todo: alon
    HealthPoints &operator-(const HealthPoints &); // todo: ofir
    HealthPoints &operator-=(const HealthPoints &); // todo: ofir
    HealthPoints &operator+(const HealthPoints &); //todo: alon
    HealthPoints &operator+=(const HealthPoints &); //todo: alon
    class InvalidArgument {};
};

bool operator!=(const HealthPoints& hp1, const HealthPoints& hp2);
bool operator>=(const HealthPoints& hp1, const HealthPoints& hp2);
bool operator>(const HealthPoints& hp1, const HealthPoints& hp2);
bool operator<=(const HealthPoints& hp1, const HealthPoints& hp2);

#endif //EX3_HEALTHPOINTS_H
