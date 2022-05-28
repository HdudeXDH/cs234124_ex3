//
// Created by User on 5/28/2022.
//
#include <fstream>
using std::ifstream;
using std::ofstream;
#include "HealthPoints.h"

int main(){
    HealthPoints healthPoints1;


    HealthPoints healthPoints2 = HealthPoints(150);

    try {
        HealthPoints healthPoints3(-100);
    }
    catch (HealthPoints::InvalidArgument& e) {

    }

    healthPoints1 -= 20; /* now has 80 points out of 100 */
    healthPoints1 +=100; /* now has 100 points out of 100 */
    healthPoints1 -= 150; /* now has 0 points out of 100 */
    healthPoints2 = healthPoints2 - 160; /* now has 0 points out of 150 */
    healthPoints2 = 160 + healthPoints1; /* now has 100 out of 100 */


    bool comparisonResult;
    HealthPoints healthPoints1(100);
    HealthPoints healthPoints2 = 100; /* 100 points out of 100 */
    comparisonResult = (healthPoints1 == healthPoints2); /* returns true */
    healthPoints2 = HealthPoints(150); /* has 150 points out of 150 */
    comparisonResult = (healthPoints1 == healthPoints2); /* returns false */
    healthPoints2 -= 50; /* now has 100 points out of 150 */
    comparisonResult = (100 == healthPoints2); /* returns true */
    comparisonResult = (healthPoints1 < healthPoints2); /* returns false */
    healthPoints1 -= 50; /* now has 50 points out of 100 */
    comparisonResult = (healthPoints1 < healthPoints2); /* returns true */


    std::cout << healthPoints1 << ", " <<

}