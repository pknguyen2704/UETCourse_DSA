
// find the intersection between line AB and line CD

#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;
class Point
{
    public:
        double x, y;
        Point()
        {
            x = 0;
            y = 0;
        }
        Point(const double& x_, const double& y_)
        {
            x = x_;
            y = y_;
        }
};
class Line
{
    public:
        Point p1, p2;
        Line(const Point& p1_, const Point& p2_)
        {
            p1 = p1_;
            p2 = p2_;
        }
        bool isParallel(const Line& other) const
        {
            return fabs((p1.x - p2.x)*(other.p1.y - other.p2.y) - (p1.y - p2.y)*(other.p1.x - other.p2.x)) < 1e-9;
        }
        bool isCoincident(const Line& other) const
        {
            if(isParallel(other))
            {
                double d1 = p1.x * (other.p1.y - other.p2.y) + p2.x * (other.p2.y - other.p1.y) + other.p1.x * (p2.y - p1.y);
                double d2 = p1.y * (other.p2.x - other.p1.x) + p2.y * (other.p1.x - other.p2.x) + other.p1.y * (p2.x - p1.x);
                return fabs(d1) < 1e-9 && fabs(d2) < 1e-9;
            }
            return false;
        }
        Point intersection(const Line& other) const
        {
            double a1 = p2.y - p1.y;
            double b1 = p1.x - p2.x;
            double c1 = p1.x*a1 + p1.y*b1;
            
            double a2 = other.p2.y - other.p1.y;
            double b2 = other.p1.x - other.p2.x;
            double c2 = other.p1.x*a2 + other.p1.y*b2;

            double det = a1*b2 - a2*b1;

            if(isParallel(other) || isCoincident(other))
                return Point();
            
            Point intersectionPoint;
            intersectionPoint.x = (b2*c1 - b1*c2)/det;
            intersectionPoint.y = (a1*c2 - a2*c1)/det;
            return intersectionPoint;

        }
};
int main()
{
    Point A, B, C, D;
    cin >> A.x >> A.y >> B.x >> B.y >> C.x >> C.y >> D.x >> D.y;
    Line AB(A, B);
    Line CD(C, D);

    if(AB.isParallel(CD))
    {
        if(AB.isCoincident(CD))
            cout <<"MANY" << endl;
        else
            cout << "NO" << endl;
    }
    else
    {
        Point intersectionPoint = AB.intersection(CD);
        cout << setprecision(2) << fixed << intersectionPoint.x  << " " << intersectionPoint.y;
    }
    return 0;
}