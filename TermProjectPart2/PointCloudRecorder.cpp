#include "PointCloudRecorder.h"
#include<fstream>
#include<vector>
using namespace std;
PointCloudRecorder::PointCloudRecorder() {};
bool const PointCloudRecorder::save(PointCloud& pc) {

    cout << "Enter file name: ";
    getline(cin, this->file_name);
    ofstream file(this->file_name);
    vector<Point*> points = pc.givePoints();
    for (int i = 0; i < points.size() - 1; ++i) {
        file << points[i]->x << " " << points[i]->y << " " << points[i]->z << endl;
    }
    int i = points.size() - 1;
    file << points[i]->x << " " << points[i]->y << " " << points[i]->z;

    file.close();
    return true;

};