#include "furthest.h"
#include "closest.h"
#include <stdio.h>
#include <float.h>
#include <stdlib.h>
#include <math.h>
#include "compare.h"
#include "Point.h"
#include "jarvis.h"
#include "readWrite.h"
#include <iostream>
using namespace std;

float furthest::dist(Point p1, Point p2)
{
    return ( (p1.x - p2.x)*(p1.x - p2.x) +
                 (p1.y - p2.y)*(p1.y - p2.y)
               );
}
void furthest::fur(Point p[], int j)
{
    int ind, ind2;
    float maxi;
    for(int i=0;i<j-1;i++)
    {
        for(int k=i+1;k<j;k++)
        {
            if(dist(p[i],p[k])>maxi)
            {
                maxi=dist(p[i],p[k]);
                ind=p[i].getId();
                ind2=p[k].getId();
            }
        }
    }
    cout<<"Distance between edges with ID" << ind << "and "<< ind2 <<"is furthest"<< sqrt(maxi)<<endl;
}
