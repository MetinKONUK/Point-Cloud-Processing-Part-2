#pragma once
#include<fstream>
#include "PointCloud.h"
#include<string>
#include<iostream>
#include<vector>

class PointCloudRecorder {
private:
    string file_name;
public:
    PointCloudRecorder();
    bool const save(PointCloud&);
};
