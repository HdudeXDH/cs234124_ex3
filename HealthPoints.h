//
// Created by User on 5/27/2022.
//

#ifndef EX3_HEALTHPOINTS_H
#define EX3_HEALTHPOINTS_H

//todo build iterface implemantation in HealthPoints.cpp
class HealthPoints {
    int m_length;
    char *m_data;

//    static char *allocateAndCopy(const char *data, int size);

public:
    HealthPoints(const int hp); // String s1; or String s1 = "aa";
//    HealthPoints(const HealthPoints &int); // String s2(s1); todo: this isnt the right syntax
    ~HealthPoints();

    HealthPoints &operator=(const HealthPoints &); // s1 = s2;
    HealthPoints &operator-=(const HealthPoints &); // s1 = s2;
    HealthPoints &operator+=(const HealthPoints &); // s1 = s2;
    class InvalidArgument {};
}


#endif //EX3_HEALTHPOINTS_H
