//
// Created by j.hoekstra on 13-5-2015.
//

#include "unitTesting.h"
#include "kinematics.h"

bool unitTesting::testCalculate(double y, double x, double z, std::array<int, 3> expectedResults)
{
    kinematics kinematics(5,10,20,10);
    std::array<double, 3> kinematicsResults = kinematics.calculate(y, x ,z);

    //Parse results to int because spreadsheet/program have different values after comma
    std::array<int, 3> results = {(int)kinematicsResults[0], (int)kinematicsResults[1], (int)kinematicsResults[2]};
    std::array<bool, 3> amountTrue;

    //Loop through results and check if they are what is expected
    for(int i=0; i<results.size(); i++)
    {
        //Check if the result is the same as what is expected
        if(results[i] == expectedResults[i])
        {
            //If this is the case add a true to our array
            amountTrue[i] = true;
        }
        //Add false otherwise
        else
        {
            amountTrue[i] = false;
        }
    }
    //Loop through the array which has checked if results are what is expected
    for(int j=0; j<amountTrue.size(); j++)
    {
        //If there is any false value in our array
        if(amountTrue[j] == false)
        {
            //Return false
            return false;
        }
    }
    return true;
}
