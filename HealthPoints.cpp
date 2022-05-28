//
// Created by User on 5/27/2022.
//

#include "HealthPoints.h"

bool operator==(const HealthPoints& hp1, const HealthPoints& hp2) {
    return hp1.points == hp2.points ;
}
//todo: check if >/<= needed also?
bool operator<(const HealthPoints& hp1, const HealthPoints& hp2) {
    return hp1.points < hp2.points;
}

std::ostream& operator<<(std::ostream& os, const HealthPoints& hp) {
    os << hp.points;
    os << "(" << hp.maxHp<< ")";
    return os;
}