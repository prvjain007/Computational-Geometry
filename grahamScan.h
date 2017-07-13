#ifndef GRAHAMSCAN_H
#define GRAHAMSCAN_H
#include "compare.h"

//!  A Graham's Scan class.
/*!
  This class inherits the basic class and computes the Convex Hull using the Graham's Scan Algorithm
*/
class grahamScan: public compare
{
    public:
        void Scan(Point p[], int n);
    protected:
    private:
};

#endif // GRAHAMSCAN_H
