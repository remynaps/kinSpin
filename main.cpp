#include "kinematics.h"
#include "unitTesting.h"
#include <iostream>

using namespace std;

int main()
{
    kinematics kinematics(4.55, 9.3, 17.3, 8.1);
    //unitTesting unitTesting;
    //bool test = unitTesting.testCalculate(0,5,-10,"009304340709");
    //std::cout << test << std::endl;
    kinematics.calculate(-2, 2, -1);
    return 0;
}