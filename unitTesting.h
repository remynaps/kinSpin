//
// Created by j.hoekstra on 13-5-2015.
//

#ifndef KINSPIN_UNITTESTING_H
#define KINSPIN_UNITTESTING_H

#include <vector>
#include "kinematics.h"
#include <string>

class unitTesting {
public:
    bool testCalculate(double y, double x, double z, std::vector<double> expectedResults);
private:

};

#endif //KINSPIN_UNITTESTING_H
