#include "RadiusOutlierFilter.h"

void RadiusOutlierFilter::filter(PointCloud& pc) {
    vector<Point*> points = pc.givePoints();
    for (int i = 0; i < points.size(); ++i) {
        double minDis = INFINITY;
        Point* p1 = points[i];
        double distance = 0;
        for (int j = 0; j < points.size(); ++j) {
            if (j == i)continue;
            Point* p2 = points[j];
            distance = p1->distance(*p2);
            if (distance < minDis)
                minDis = distance;
        }
        if (this->radius > minDis)
            points.erase(points.begin() + i);
    }
    pc.setpn(points.size());
    pc.setPoints(points);
};
