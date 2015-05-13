//
// Created by j.hoekstra on 12-5-2015.
//

#include "kinematics.h"
#include <iostream>

kinematics::kinematics(double coxa, double femur, double tibia, double standardHeight)
{
    this->coxa = coxa;
    this->femur = femur;
    this->tibia = tibia;
    this->standardHeight = standardHeight;
}

kinematics::~kinematics()
{
}

//L is the Length between tip of the Tibia to the servo that connects Coxa+Femur
double kinematics::calcL()
{
    return sqrt(pow(calcZoffset(), 2) + pow((calcL1()-coxa), 2));
}

//L1 is the Length between tip of the Tibia to where the Coxa starts
double kinematics::calcL1()
{
    return sqrt(pow(x,2)+pow(y,2));
}

//The Alpha 1 angle is calculated by the acos of the zOffset/L
double kinematics::calcAlpha1()
{
    return acos(calcZoffset()/calcL());
}

//To calculate Alpha 2 angle we use the cosine rule
double kinematics::calcAlpha2()
{
    return acos((pow(tibia, 2) - pow(femur, 2) - pow(calcL(), 2)) / (-2 * femur * calcL()));
}

//To calculate Beta angle we use the cosine rule
double kinematics::calcBeta()
{
    return acos((pow(calcL(), 2) - pow(tibia, 2) - pow(femur, 2)) / (-2 * tibia * femur));
}

//The Gamma angle is calculated by the atan of y/x
double kinematics::calcGamma()
{
    return atan(y/x);
}

//To calculate the zOffset we need to know the different between the standard height and our z value
//This value need to be absolute!
double kinematics::calcZoffset()
{
    int zoffset1 = standardHeight - z;
    zoffset1 = getAbsolute(zoffset1);
    return zoffset1;
}

//Function to return the absolute of a double
double kinematics::getAbsolute(double val)
{
    if(val < 0)
    {
        val *= -1;
    }
    return val;
}

//Function to calculate where the servo's need to move to get desired y,x and z values
std::array<double, 3> kinematics::calculate(double y, double x, double z)
{
    this->x = x;
    this->y = y;
    this->z = z;
    std::array<double, 3> values = {0,0,0};

    //Calculate the angles
    double alpha = calcAlpha1() + calcAlpha2();
    double beta = calcBeta();
    double gamma = calcGamma();

    //Convert to degrees
    values[0] = (alpha) * (180/3.14);
    values[1] = (beta) * (180/3.14);
    values[2] = (gamma) * (180/3.14);

    std::cout << values[0] << std::endl;
    std::cout << values[1] << std::endl;
    std::cout << values[2] << std::endl;

    return values;
}