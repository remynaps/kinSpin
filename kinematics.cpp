//
// Created by j.hoekstra on 12-5-2015.
//

#include "kinematics.h"
#include <iostream>
#include <sstream>
#include <cmath>

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
    //z=getAbsolute(z);
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
std::vector<double> kinematics::calculate(double y, double x, double z)
{
    this->x = x;
    this->y = y;
    this->z = z;
    std::vector<double> results;

    //Calculate the angles
    double alpha = calcAlpha1() + calcAlpha2();
    double beta = calcBeta();
    double gamma = calcGamma();

    //Convert to degrees and then to servo positions
    results.push_back(std::round(((alpha) * (180/3.141592653589793) - 43) * 3.41));
    results.push_back(std::round(((beta) * (180/3.141592653589793) + 30.5) * 3.41));
    results.push_back(std::round(((gamma) * (180/3.141592653589793) + 150) * 3.41));

    //Print the results in degrees and servo angles
   // std::cout<< (alpha) * (180/3.141592653589793)<<std::endl;
   // std::cout<< (beta) * (180/3.141592653589793)<<std::endl;
   // std::cout<< (gamma) * (180/3.141592653589793)<<std::endl;
    std::cout << results[0] << std::endl;
    std::cout << results[1] << std::endl;
    std::cout << results[2] << std::endl;

    //std::cout<<result<<std::endl;

    return results;
}