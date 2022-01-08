#include <iostream>
#include<iomanip>
#include <vector>
#include "Point.h"
#include "PointCloud.h"
#include "PassThroughFilter.h"
#include "DepthCamera.h"
#include "RadiusOutlierFilter.h"
#include "Transform.h"
#include "PointCloudRecorder.h"
#define PI 3.141592653589793238462643383279502884197169399375105820974944592307816406286208998628034825342117067982148086513282306647
using namespace std;

void list_point_cloud_points(vector<Point*> points) {
    for (int i = 0; i < points.size(); ++i) {
        cout
            << "Point " << i
            << ": (" << points[i]->x
            << ',' << points[i]->y
            << ',' << points[i]->z
            << ')' << endl;
    }
};
int main() {

    DepthCamera dc;
    PointCloudRecorder pcr;
    RadiusOutlierFilter rof;
    PassThroughFilter ptf1(400, 0, 400, 0, 45, -45);
    PassThroughFilter ptf2(500, 0, 500, 0, 45, -45);
    Transform tf1;
    double angles1[3] = { -PI / 2, 0, 0 }; // alpha beta omega
    double trans1[3] = { 100, 500, 50 }; // x, y, z
    tf1.setRotation(angles1);
    tf1.setTranslation(trans1);

    Transform tf2;
    double angles2[3] = { PI / 2, 0, 0 }; // alpha beta omega
    double trans2[3] = { 550, 150, 50 }; // x, y, z
    tf2.setRotation(angles2);
    tf2.setTranslation(trans2);

    PointCloud pc1 = dc.capture();
    PointCloud pc2 = dc.capture();

    rof.filter(pc1);
    rof.filter(pc2);

    ptf1.filter(pc1);
    ptf2.filter(pc2);

    pc1 = tf1.doTransform(pc1);
    pc2 = tf2.doTransform(pc2);

    PointCloud pc3 = pc1 + pc2;
    pcr.save(pc3);
};