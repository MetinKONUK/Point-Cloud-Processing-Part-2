#include "Point.h"
using namespace std;

Point::Point(double a = 0, double b = 0, double c = 0) :x(a), y(b), z(c) {};
bool Point::operator==(const Point& p) const {
    if (x == p.x && y == p.y && z == p.z)
        return true;
    return false;
}
const double Point::distance(const Point& p) {
    return sqrt(pow(this->x - p.x, 2) + pow(this->y - p.y, 2) + pow(this->z - p.z, 2));
};