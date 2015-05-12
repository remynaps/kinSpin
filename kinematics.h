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
    double calcL();
    double calcL1();
    double calcAlpha1();
    double calcAlpha2();
    double calcBeta();
    double calcGamma();
    double calcZoffset();
    double getAbsolute(double val);
    std::array<double, 3> calculate(int y, int x, int z);
    kinematics();
    ~kinematics();

private:
    int coxa = 5;
    int femur = 10;
    int tibia = 20;
    double x;
    double y;
    double z;
    int standardHeight = 10;
};
#endif //KINEMATICSTEST_KINEMATICS_H
