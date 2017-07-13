#include "compare.h"
#include "Point.h"
#include "jarvis.h"
#include "readWrite.h"
#include <bits/stdc++.h>
#include <fstream>
using namespace std;

//! A normal member taking two arguments and returning void.
/*!
  \sa andrew()
  \param n an integer argument.
  \param p a Point array pointer.
*/
int jarvis::jarvi(Point p[], int n, Point b[])
{
    int curr,curr2,ind,j=0,k=1;//! A float.
    /*! To store the number of points in Convex-Hull and other indexes*/
    ind=leftmost(p,n);
    curr=ind;
    //! A Point.
    /*! This will store the actual points in Convex-Hull*/
    do{
        curr2=(curr+1)%n;
        b[j++]=p[curr];
        for(int i=0;i<n;i++)
        {
            int r=counter_clockwise(p[curr],p[curr2],p[i]);
            if(r==1)
            {
                k=0;
                curr2=i;
            }

            else if(r==0)
            {
                k=1;
            }

        }
        curr=curr2;
    }while(curr!=ind);
    return j;

}
