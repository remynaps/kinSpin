//
// Created by j.hoekstra on 13-5-2015.
//

#ifndef KINSPIN_UNITTESTING_H
#define KINSPIN_UNITTESTING_H


#include <array>
#include "kinematics.h"

class unitTesting {
public:
    bool testCalculate(double y, double x, double z, kinematics::servoAngles expectedResults);
private:



};


#endif //KINSPIN_UNITTESTING_H
