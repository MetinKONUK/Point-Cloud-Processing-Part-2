#pragma once
#include<vector>
class Point {
public:
    double x, y, z;
public:
    Point(double, double, double);
    bool operator==(const Point& p) const;
    const double distance(const Point&);
};