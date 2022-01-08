#pragma once
#include "PointCloud.h"
#include<iostream>
#include<fstream>
#include <string>
using namespace std;

class DepthCamera {
private:
    string file_name;
public:
    DepthCamera();
    PointCloud capture();
};