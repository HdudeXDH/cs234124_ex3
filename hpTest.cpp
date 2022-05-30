//
// Created by User on 5/28/2022.
//
#include <fstream>
using std::ifstream;
using std::ofstream;
#include "HealthPoints.h"
#include "Queue.h"


void hpChecks(){
    HealthPoints healthPoints3;


    HealthPoints healthPoints4 = HealthPoints(150);

    try {
        HealthPoints healthPoints3(-100);
    }
    catch (HealthPoints::InvalidArgument& e) {

    }

    healthPoints3 -= 20; /* now has 80 points out of 100 */
    healthPoints3 +=100; /* now has 100 points out of 100 */
    healthPoints3 -= 150; /* now has 0 points out of 100 */
    healthPoints4 = healthPoints4 - 160; /* now has 0 points out of 150 */
    healthPoints4 = 160 + healthPoints3; /* now has 100 out of 100 */


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
}

bool is2(T t){
    bool res=t==2;
    return res;
}

void funcT(T & som){
    som=8;
}
void queueCheckInt(){
    Queue queue1;
    queue1.pushBack(1);
    queue1.pushBack(2);

    int front1 = queue1.front(); /* front1 equals 1 as its the first value */
    queue1.front() = 3; /* queue1 content is: 3, 2 (left to right) */
    front1 = queue1.front(); /* front1 now equals 3 */

    queue1.popFront();

    int size1 = queue1.size();
    Queue q2 = queue1;
    q2.pushBack(2);
    bool t1 = q2.begin()==queue1.begin();
    bool t2 = q2.end()==queue1.end();
    queue1.popFront();
    for (Queue::Iterator it = queue1.begin(); it != queue1.end(); ++it) {
        T t =  *it;
    }

    queue1.pushBack(1);
    queue1.pushBack(2);
    transform(queue1,funcT);
    q2.pushBack(1);
    q2.pushBack(3);
//    Queue q5;
    Queue q5 = filter(q2, is2);
//    Queue q3 = queue1;
    Queue q6(q2);





}

int main(){
    queueCheckInt();



}