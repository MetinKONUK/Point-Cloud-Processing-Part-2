#pragma once
#include "PointCloud.h"
class RadiusOutlierFilter {
private:
    double radius = 25;
public:
    void filter(PointCloud&);
};