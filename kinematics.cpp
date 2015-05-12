//
// Created by j.hoekstra on 12-5-2015.
//

#include "kinematics.h"
#include <iostream>

kinematics::kinematics()
{
}

kinematics::~kinematics()
{
}

double kinematics::calcL()
{
    return sqrt(pow(calcZoffset(), 2) + pow((calcL1()-coxa), 2));
}

double kinematics::calcL1()
{
    return sqrt(pow(x,2)+pow(y,2));
}

double kinematics::calcAlpha1()
{
    return acos(calcZoffset()/calcL());
}

double kinematics::calcAlpha2()
{
    return acos((pow(tibia, 2) - pow(femur, 2) - pow(calcL(), 2)) / (-2 * femur * calcL()));
}

double kinematics::calcBeta()
{
    return acos((pow(calcL(), 2) - pow(tibia, 2) - pow(femur, 2)) / (-2 * tibia * femur));
}

double kinematics::calcGamma()
{
    return atan(y/x);
}

double kinematics::calcZoffset()
{
    int zoffset1 = standardHeight - z;
    zoffset1 = getAbsolute(zoffset1);
    return zoffset1;
}

double kinematics::getAbsolute(double val)
{
    if(val < 0)
    {
        val *= -1;
    }
    return val;
}

std::array<double, 3> kinematics::calculate(int y, int x, int z)
{
    this->x = x;
    this->y = y;
    this->z = z;
    std::array<double, 3> values = {0,0,0};
    double alpha = calcAlpha1() + calcAlpha2();
    double beta = calcBeta();
    double gamma = calcGamma();
    values[0] = (alpha) * (180/3.14);
    values[1] = (beta) * (180/3.14);
    values[2] = (gamma) * (180/3.14);

    std::cout << values[0] << std::endl;
    std::cout << values[1] << std::endl;
    std::cout << values[2] << std::endl;

    return values;
}