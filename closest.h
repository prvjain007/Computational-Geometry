#ifndef CLOSEST_H
#define CLOSEST_H
#include "compare.h"

class closest:public compare
{
    public:
        float closestUtil(Point P[], int n);
        float dist(Point p1, Point p2);
        float bruteForce(Point P[], int n);
        float mini(float x, float y);
        float stripClosest(Point strip[], int sizi, float d);

        float closes(Point P[], int n);
    protected:
    private:
};

#endif // CLOSEST_H
