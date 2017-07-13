#include "compare.h"
#include "Point.h"
#include <bits/stdc++.h>
#include <fstream>
using namespace std;
//! A normal member taking two arguments and returning leftmost Point.
/*!
  \param p Points inputted.
  \param n number of points.
  \return ind index of leftmost Point.
*/
int compare::leftmost(Point p[], int n)
{
    float mi=1e9;//! A float.
    /*! To find minimum point */
    int ind;//! An Int.
    /*! Index to be returned */
    for(int i=0;i<n;i++)
    {
        if(p[i].getX()<mi)
        {
            mi=p[i].getX();
            ind=i;
        }
    }
    return ind;
}
//! A normal member taking two arguments and returning lowest Point.
/*!
  \param p Points inputted.
  \param n number of points.
  \return ind index of lowest Point.
*/
int compare::lowest(Point p[], int n)
{

    float miY=1e9,miX=1e9;//! Two floats.
    /*! To find minimum point with lowest Y and corresponding X co-ordinate*/
    int ind;//! An Int.
    /*! Index to be returned */
    for(int i=0;i<n;i++)
    {

        if(p[i].getY()<miY)
        {
            miY=p[i].getY();
            miX=p[i].getX();
            ind=i;
        }
        else if(p[i].getY()==miY)
        {
            if(p[i].getX()<miX)
            {
                miX=p[i].getX();
                ind=i;
            }
        }
    }

    return ind;
}
//! A normal member taking four arguments and returning the convex hull of Points
/*!
  \param p Points inputted.
  \param n number of points.
  \param cc To tell if the turn if we desire is clock-wise or anti clock-wise
  \param b Points in convex hull
  \return j number of Points in Convex Hull
*/

int compare::hull(Point p[], int n, Point z[], int cc)
{
    compare c;
    int j=0,k=0,r;
    for(int i=0;i<n;i++)
    {
//    int r=c.counter_clockwise(z[j-2],z[j-1],p[i]);
//    cout<<r<<endl;
//    if(r==0)

    while(j>1 && c.counter_clockwise(z[j-2],z[j-1],p[i])==cc)
    {
            j--;
            k=1;
    }

    z[j++]=p[i];

    }
    if(k==0)
        return 0;
    return j;
}

//! A comparing functions taking two arguments sorts the Points by X co-ordinates
/*!
  \param e1 Point A
  \param e2 Point B
  \return boolean which compares
*/
bool compare::SortByX( Point e1,  Point e2)
{

    if(e2.getX()>e1.getX())
        return 1;
    else if(e2.getX()==e1.getX())
        if( e2.getY() < e1.getY())
            return 1;
    return 0;

}
//! A comparing functions taking two arguments and call sort function
/*!
  \param p Point A
  \param n number of points
*/
void compare::sortX(Point p[], int n)
{
    sort(p,p+n,SortByX);
}
bool compare::SortByY( Point e1,  Point e2)
{

    if(e2.getY()>e1.getY())
        return 1;
    else if(e2.getY()==e1.getY())
        if( e2.getX() < e1.getX())
            return 1;
    return 0;

}
//! A comparing functions taking two arguments and call sort function
/*!
  \param p Point A
  \param n number of points
*/
void compare::sortY(Point p[], int n)
{
    sort(p,p+n,SortByY);
}
//! A comparing functions taking two arguments sorts the Points with the angle
/*!
  \param e1 Point A
  \param e2 Point B
  \return boolean which compares
*/
bool compare::SortByAngle( Point e1,  Point e2)
{

    float m1=(e2.getX()-xxx)*(e1.getY()-yyy),m2=(e2.getY()-yyy)*(e1.getX()-xxx)//! Two floats.
    /*! To compare slopes of two lines*/;


    if(m1>m2)
            return 0;
    else if (m1==m2)
    {
        if(e1.getY()  > e2.getY())
            return 0;
    }
        return 1;
}
float compare::xxx=0;//! A float.
    /*! Value corresponding to minimum X*/
float compare::yyy=0;//! A float.
    /*! Value corresponding to minimum Y*/
//! A comparing functions taking two arguments and call sort function
/*!
  \param p Point A
  \param n number of points
*/
void compare::SortAngle(Point p[], int n)
{
    compare c;

    int d=c.leftmost(p,n);
    xxx=p[d].getX();
    yyy=p[d].getY();
    sort(p,p+n,SortByAngle);
}
//! A normal member taking three arguments and returns whether the points are Clockwise, Collinear or anti-Clockwise
/*!
  \param a Point A
  \param b Point B
  \param b Point C
  \return 1 for counter clockwise -1 for clockwise and 0 for collinear
  \param cc To tell if the turn if we desire is clock-wise or anti clock-wise
*/
int compare::counter_clockwise(Point a, Point b,Point c)
{
    float x1,y1,x2,y2;//! Four floats.
    /*! To find Cross-Product which will find direction of rotation*/
    x1=b.getX()-a.getX();
    y1=b.getY()-a.getY();
    x2=c.getX()-a.getX();
    y2=c.getY()-a.getY();
    if(x1*y2>y1*x2)
        return 1;
    else if(x1*y2<y1*x2)
        return -1;
    else
        return 0;
}
//! A comparing functions taking two arguments and sets the ID of all the points
/*!
  \param p Point A
  \param n number of points
*/
void compare::iid(Point p[], int n)
{
    for(int i=0;i<n;i++)
    {
       p[i].setId(i);
    }

}
