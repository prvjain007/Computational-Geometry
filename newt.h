#ifndef NEWT_H
#define NEWT_H
#include "Point.h"
#include "compare.h"

//!  A Andrew class.
/*!
  This class inherits the basic class and computes the Convex Hull using the Andrew Algorithm
*/
class newt:public compare
{
    public:
        void andrew(Point p[], int n);
    protected:
    private:
};

#endif // NEWT_H
