#include "HealthPoints.h"

HealthPoints::HealthPoints(const int hp):
    m_points(hp),
    m_maxHp(hp) {
    if (hp<=0){
        throw HealthPoints::InvalidArgument();
    }

}

bool operator!=(const HealthPoints& hp1, const HealthPoints& hp2){
    bool equal = hp1==hp2;
    return not equal;
}

bool operator>=(const HealthPoints& hp1, const HealthPoints& hp2){
    bool bigger = hp2<hp1;
    bool equal = hp2==hp1;
    return bigger|equal;
}
bool operator>(const HealthPoints& hp1, const HealthPoints& hp2){
    return  hp2<hp1;
}

bool operator<=(const HealthPoints& hp1, const HealthPoints& hp2){
    return  hp2>=hp1;
}


bool operator==(const HealthPoints& hp1, const HealthPoints& hp2) {
    return hp1.m_points == hp2.m_points ;
}

bool operator<(const HealthPoints& hp1, const HealthPoints& hp2) {
    return hp1.m_points < hp2.m_points;
}

std::ostream& operator<<(std::ostream& os, const HealthPoints& hp1) {
    os << hp1.m_points;
    os << "(" << hp1.m_maxHp<< ")";
    return os;
}

HealthPoints& HealthPoints::operator+=(const int points){
    if (points<0) {
        return *this -= (-points);
    }
    if((this->m_points + points) >= this->m_maxHp) {
        this->m_points = this->m_maxHp;}
    else this->m_points += points;
    return *this;
}

HealthPoints operator+(const int points, const HealthPoints& hp1){
    HealthPoints temp_hp = hp1;
    temp_hp += points;
    return temp_hp;
}
HealthPoints operator+(const HealthPoints& hp1, const int points){
    HealthPoints temp_hp = hp1;
    temp_hp += points;
    return temp_hp;
}


HealthPoints& HealthPoints::operator-=(const int points){
    if (points<0) {
        return *this += (-points);
    }
    if((this->m_points - points) <= 0) {this->m_points = 0;}
    else {this->m_points -= points;}
    return *this;
}

HealthPoints operator-(const HealthPoints& hp1, const int points){
    HealthPoints temp_hp = hp1;
    temp_hp -= points;
    return temp_hp;
}

HealthPoints operator-(const int points, const HealthPoints& hp1){
    HealthPoints temp_hp = hp1;
    temp_hp -= points;
    return temp_hp;
}