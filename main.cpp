#include "newt.h"
#include "compare.h"
#include "Point.h"
#include "grahamScan.h"
#include "jarvis.h"
#include "readWrite.h"
#include <bits/stdc++.h>
#include <fstream>
#define mp make_pair
#define pb push_back
#include "closest.h"
#include "furthest.h"
using namespace std;

//!  Main Function
/*!
  This function is responsible for all the work to be done
*/







int main()
{

    int n;//! An integer.
    /*! Number of Points */
    cout<<"This program loads convex hull co-ordinates in .ch file"<<endl;
    cout<<"Enter the number of Points- ";
    cin>>n;
    Point p[n];
    readWrite rs;
    Point b[n];
    float f, ff;
    ifstream theFile("read.txt");
    int i=0, in;
    while(theFile >> f  >> ff >> in)
    {
        p[i].setX(f);
        p[i].setY(ff);
        p[i].setId(i);
        i++;
    }

    jarvis jj;
    int j;
    j=jj.jarvi(p,n,b);
    readWrite w;
    w.write(p,n,j,b);
    closest c;
    cout<<c.closes(p,n);

    furthest fff;
    fff.fur(b,j);

    return 0;
}
