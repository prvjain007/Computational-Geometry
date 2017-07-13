#include "newt.h"
#include "compare.h"
#include "Point.h"
#include "readWrite.h"
#include <bits/stdc++.h>
using namespace std;


//! A normal member taking two arguments and returning void.
/*!
  \sa andrew()
  \param n an integer argument.
  \param p a Point array pointer.
*/


void newt::andrew(Point p[], int n)
{
    sortX(p,n);
    iid(p,n);
    Point a[n],b[n];//! A Point.
    /*! This will store the actual points in Upper-Hull and Lower hull*/
    int l=hull(p,n,b,-1); //! This returns the number of Points in lower hull
    int u=hull(p,n,a,1);  //! This returns the number of Points in upper hull
    if(l+u==0)
    {
        cout<<"Collinear Points"<<endl;
        return;
    }

    cout<<l<<u<<endl;
    for(int i=0;i<u;i++)
        b[i+l]=a[u-i];
    readWrite w;
    w.write(p,n,l+u,b);

}
