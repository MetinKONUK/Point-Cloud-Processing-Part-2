#pragma once
#include "Point.h"
using namespace std;

class PointCloud {
private:
    vector<Point*> points; //+
    int pointNumber; //+
public:
    PointCloud(int); //+
    PointCloud operator+(const PointCloud&); //+
    //setter getter added 
    void addPoint(Point*);
    vector<Point*> givePoints();
    void setPoints(vector<Point*>);
    void setpn(int);
    int getpn();

};