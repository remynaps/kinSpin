//
// Created by j.hoekstra on 13-5-2015.
//

#include "unitTesting.h"

bool unitTesting::testCalculate(double y, double x, double z, std::string expectedResults)
{
    kinematics kinematics(4.55,9.3,17.3);
    std::string kinematicsResults = kinematics.calculate(y, x ,z);

    if(expectedResults == kinematicsResults)
    {
        return true;
    }
    return false;
}
