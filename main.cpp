#include "kinematics.h"
#include "unitTesting.h"
#include <iostream>

using namespace std;

int main() {
    //kinematics kinematics(5,10,20);
    unitTesting unitTesting;
    bool test = unitTesting.testCalculate(10,15,4,{174,42,33});
    std::cout << test << std::endl;
    //kinematics.calculate(10,15,4);
    return 0;
}