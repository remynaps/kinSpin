//
// Created by j.hoekstra on 12-5-2015.
//
#pragma once

#include <array>
#include "math.h"
#ifndef KINEMATICSTEST_KINEMATICS_H
#define KINEMATICSTEST_KINEMATICS_H

class kinematics {
public:
    std::string calculate(double y, double x, double z);
    kinematics(double coxa, double femur, double tibia, double standardHeight);
    ~kinematics();

private:
    double coxa;
    double femur;
    double tibia;
    double x;
    double y;
    double z;
    double standardHeight;

    std::string formatString(std::string text);
    double calcL();
    double calcL1();
    double calcAlpha1();
    double calcAlpha2();
    double calcBeta();
    double calcGamma();
    double calcZoffset();
    double getAbsolute(double val);
};

#endif //KINEMATICSTEST_KINEMATICS_H
