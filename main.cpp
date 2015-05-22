#include "kinematics.h"
#include "unitTesting.h"
#include <iostream>

using namespace std;

int main() {
    //kinematics kinematics(4.55,9.3, 17.3,8);
    unitTesting unitTesting;
    bool test = unitTesting.testCalculate(8,5,-20,"009304340709");
    std::cout << test << std::endl;
    //kinematics.calculate(0,17,-8);
    return 0;
}

