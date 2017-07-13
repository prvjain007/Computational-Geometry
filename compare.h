#ifndef COMPARE_H
#define COMPARE_H
#include "Point.h"

//!  A Basic class.
/*!
  This class contains the functions which are needed by other classes
*/
class compare
{

    public:
        int leftmost(Point p[], int n);
        int lowest(Point p[], int n);
        int hull(Point p[], int n, Point b[], int cc);
        int hull1(Point p[], int n, Point b[], int cc);
        static bool SortByX( Point e1,  Point e2);
        static bool SortByY( Point e1,  Point e2);
        static int counter_clockwise(Point a, Point b, Point c);
        static bool SortByAngle( Point e1,  Point e2);
        static float xxx,yyy;
        void SortAngle(Point p[], int n);
        void sortX(Point p[], int n);
        void sortY(Point p[], int n);

        void iid(Point p[], int n);
    protected:
    private:

};

#endif // COMPARE_H
