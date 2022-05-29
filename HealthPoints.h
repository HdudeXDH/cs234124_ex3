//
// Created by User on 5/27/2022.
//
#include <fstream>
#include <iostream>
using std::ifstream;
using std::ofstream;

#ifndef EX3_HEALTHPOINTS_H
#define EX3_HEALTHPOINTS_H

class HealthPoints {

public:
    HealthPoints(const int hp=HP_DEFAULT);
    HealthPoints(const HealthPoints &hp_instance)= default;
    ~HealthPoints()= default;
    HealthPoints &operator=(const HealthPoints& hp)= default;
    HealthPoints &operator-=(const int points);
    HealthPoints &operator+=(const int points);
    class InvalidArgument {};

private:
    static const int HP_DEFAULT = 100;
    int m_points;
    int m_maxHp;
    friend std::ostream& operator<<(std::ostream& os, const HealthPoints& r);
    friend bool operator==(const HealthPoints& hp1, const HealthPoints& hp2);
    friend bool operator<(const HealthPoints& hp1, const HealthPoints& hp2);
};

HealthPoints operator-(const HealthPoints& hp1, const int points);
HealthPoints operator+(const int points, const HealthPoints& hp1);


bool operator!=(const HealthPoints& hp1, const HealthPoints& hp2);
bool operator>=(const HealthPoints& hp1, const HealthPoints& hp2);
bool operator>(const HealthPoints& hp1, const HealthPoints& hp2);
bool operator<=(const HealthPoints& hp1, const HealthPoints& hp2);

#endif //EX3_HEALTHPOINTS_H
