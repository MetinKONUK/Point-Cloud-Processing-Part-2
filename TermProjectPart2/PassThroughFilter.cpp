#include "PassThroughFilter.h"
using namespace std;

PassThroughFilter::PassThroughFilter(double ux, double lx, double uy, double ly, double uz, double lz)
    : upperLimitX(ux), upperLimitY(uy), upperLimitZ(uz),
    lowerLimitX(lx), lowerLimitY(ly), lowerLimitZ(lz)
{

};

void PassThroughFilter::filter(PointCloud& pc) {
    vector<Point*> points = pc.givePoints();
    int i = 0;
    while (i < points.size()) {
        bool c1 = points[i]->x < lowerLimitX || points[i]->x > upperLimitX;
        bool c2 = points[i]->y < lowerLimitY || points[i]->y > upperLimitY;
        bool c3 = points[i]->z < lowerLimitZ || points[i]->z > upperLimitZ;

        if (c1 || c2 || c3) {
            points.erase(points.begin() + i);
            continue;
        }
        i++;
    }
    pc.setpn(points.size());
    pc.setPoints(points);
};