#pragma once
#include "PointCloud.h"
#include "Point.h"
#define PI 3.141592653589793238462643383279502884197169399375105820974944592307816406286208998628034825342117067982148086513282306647
class Transform {
private:
    double angles[3] = { 0 }; // alpha beta omega
    double trans[3]; // x, y, z
    double transMatrix[4][4]; // transformation matrix
    double rotationMatrix[3][3]; //rotation matrix
public:
    Transform();
    void setRotation(double[3]);
    void setTranslation(double[3]);
    Point doTransform(Point);
    PointCloud doTransform(PointCloud);
};