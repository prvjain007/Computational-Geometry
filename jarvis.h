#ifndef JARVIS_H
#define JARVIS_H
#include "compare.h"

//!  A Jarvis class.
/*!
  This class inherits the basic class and computes the Convex Hull using the Jarvis Algorithm
*/
class jarvis:public compare
{
    public:
        int jarvi(Point p[],int n, Point b[]);
    protected:
    private:
};

#endif // JARVIS_H
