#pragma once
#include "PointCloud.h"
#include<vector>
class PassThroughFilter {
private:
    double upperLimitX, upperLimitY, upperLimitZ;
    double lowerLimitX, lowerLimitY, lowerLimitZ;
public:
    PassThroughFilter(double, double, double, double, double, double);
    void filter(PointCloud&);
};