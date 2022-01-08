#include "PointCloud.h"
using namespace std;

PointCloud::PointCloud(int pn) :pointNumber(pn) {};
void PointCloud::addPoint(Point* p) { points.push_back(p); };
vector<Point*> PointCloud::givePoints() { return points; };
void PointCloud::setpn(int n) { this->pointNumber = n; };
int PointCloud::getpn() { return this->pointNumber; };
void PointCloud::setPoints(vector<Point*> points) { this->points = points; };

PointCloud PointCloud::operator+(const PointCloud& pc) {
    vector<Point*> ps1 = this->givePoints(), ps2 = pc.points;
    for (unsigned int i = 0; i < ps2.size(); ++i) {
        bool isin = false;
        for (unsigned int j = 0; j < ps1.size(); ++j)
            if (ps2[i]->x == ps1[j]->x && ps2[i]->y == ps1[j]->y && ps2[i]->z == ps1[j]->z)
                isin = true;
        if (isin == false)
            ps1.push_back(ps2[i]);
    }
    PointCloud result(ps1.size());
    result.setPoints(ps1);
    return result;
}

