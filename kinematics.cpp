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
    return atan(x/y);
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

std::array<double, 3> kinematics::calculate(int x1, int y1, int z1)
{
    x = x1;
    y = y1;
    z = z1;
    std::array<double, 3> values = {0,0,0};
    int alpha = calcAlpha1() + calcAlpha2();
    int beta = calcBeta();
    int gamma = calcGamma();
    values[0] = (gamma + 150) * 3.41;
    values[1] = (alpha + 180) * 3.41;
    values[2] = (beta + 180) * 3.41;

    std::cout << values[0] << std::endl;
    std::cout << values[1] << std::endl;
    std::cout << values[2] << std::endl;

    return values;
}