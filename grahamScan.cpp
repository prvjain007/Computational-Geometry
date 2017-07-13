#include "grahamScan.h"
#include "compare.h"
#include "Point.h"
#include "readWrite.h"
#include <bits/stdc++.h>
using namespace std;
//! A normal member taking two arguments and returning void.
/*!
  \sa Scan()
  \param n an integer argument.
  \param p a Point array pointer.
*/
void grahamScan::Scan(Point p[], int n)
{
    SortAngle(p,n);
    Point b[n];//! A Point.
    /*! This will store the actual points in Convex-Hull*/
    iid(p,n);
    int j=hull(p,n,b,-1);
    if(j==0)
    {
        cout<<"Collinear Points"<<endl;
        return;
    }
    int d=leftmost(p,n);
    b[j++]=p[d];
    readWrite w;
    w.write(p,n,j,b);
}
