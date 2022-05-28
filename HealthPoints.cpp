//
// Created by User on 5/27/2022.
//

#include "HealthPoints.h"

HealthPoints::HealthPoints(const int hp):
    points(hp),
    maxHp(hp) {
    if (hp<=0){
        throw HealthPoints::InvalidArgument();
    }

}

//todo:
HealthPoints::operator int() const {
    return points;
}

bool operator!=(const HealthPoints& hp1, const HealthPoints& hp2){
    bool equal = hp1==hp1;
    return not equal;
};
bool operator>=(const HealthPoints& hp1, const HealthPoints& hp2){
    bool bigger = hp2<hp1;
    bool equal = hp2==hp1;
    return bigger|equal;
};
bool operator>(const HealthPoints& hp1, const HealthPoints& hp2){
    return  hp2>hp1;
}

bool operator<=(const HealthPoints& hp1, const HealthPoints& hp2){
    return  hp2>=hp1;
};

//todo: != should work too
bool operator==(const HealthPoints& hp1, const HealthPoints& hp2) {
    return hp1.points == hp2.points ;
}
//todo: check if >,<=,>= needed also?
bool operator<(const HealthPoints& hp1, const HealthPoints& hp2) {
    return hp1.points < hp2.points;
}

std::ostream& operator<<(std::ostream& os, const HealthPoints& hp) {
    os << hp.points;
    os << "(" << hp.maxHp<< ")";
    return os;
}