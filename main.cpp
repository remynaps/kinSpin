#include "kinematics.h"
#include "unitTesting.h"
#include <iostream>

using namespace std;

int main() {
    kinematics kinematics(4.5,10,15.5,8);
    //unitTesting unitTesting;
//    bool test = unitTesting.testCalculate(10,15,4,{174,42,33});
 //   std::cout << test << std::endl;
    kinematics.calculate(0,17,-8);
    return 0;
}