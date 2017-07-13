#include "readWrite.h"
#include "newt.h"
#include "grahamScan.h"
#include "jarvis.h"
#include "compare.h"
#include "Point.h"
#include <bits/stdc++.h>
#include <fstream>
using namespace std;

//! A normal member taking four arguments and returning void. This function writes the co-ordinates into example.ch file.
/*!
  \param p Points inputted.
  \param n number of points.
  \param j Total Points in convex hull
  \param b Points in convex hull
*/
void readWrite::write(Point p[], int n, int j, Point b[])
{
    ofstream myfile ("example.ch");
    myfile<<"CH\n";
    myfile<<n<<" "<<j<<endl;
    for(int i=0;i<n;i++)
    {
        myfile<<p[i].getX()<<" "<<p[i].getY()<<" 0\n";
    }

    cout<<j<<endl;
    for(int i=0;i<j;i++)
        myfile<<b[i].getId()<<" ";
}
void readWrite::writee(Point p[], int n, Point d[], int l, Point e[], int m)
{
    ofstream myfile ("example1.ply");
    myfile<<"ply\n"<<"format ascii 1.0\n"<<"element vertex "<<n<<"\n"<<"property float x\n"<<"property float y\n"<<"property float z\n"<<"element face 2\n";
    myfile<<"property list uchar int vertex_index\n"<<"end_header\n";
    for(int i=0;i<n;i++)
    {
        myfile<<p[i].getX()<<" "<<p[i].getY()<<" 0\n";
    }
    myfile<<l<<" ";
    for(int i=0;i<l;i++)
        myfile<<d[i].getId()<<" ";
    myfile<<"\n";
    myfile<<m<<" ";
    for(int i=0;i<m;i++)
        myfile<<e[i].getId()<<" ";
}
void readWrite::writeee(Point p[], int n, Point d[], int l, Point e[], int m)
{
    ofstream myfile ("polyt.ply");
    myfile<<"ply\n"<<"format ascii 1.0\n"<<"element vertex "<<n<<"\n"<<"property float x\n"<<"property float y\n"<<"property float z\n"<<"element face 7\n";
    myfile<<"property list uchar int vertex_index\n"<<"end_header\n";
    if(n==8)
    {

    for(int i=0;i<n;i++)
    {
        myfile<<p[i].getX()<<" "<<p[i].getY()<<" 0\n";
    }
    myfile<<"3 0 1 2\n3 1 6 3\n3 6 4 3\n3 5 6 4\n3 2 6 5\n3 2 5 7\n3 2 7 0";
    }

}

//! A normal member taking two arguments and returning void. This function reads Points from a file read.txt
/*!
  \param p Points inputted.
  \param n number of points.
*/
void readWrite::read(Point p[],int n, Point b[])
{
    int ind=1;
    if(n<3)
    {
        cout<<"No Polygon can be formed less than three points"<<endl;
        return ;
    }
    cout<<"Enter 1 for Jarvis \n Enter 2 for Andrew \n Enter 3 for Graham's Scan\n"<<endl;
    //cin>>ind;
    float f, ff;
    ifstream theFile("point.txt");
    int i=0, in;
    while(theFile >> f  >> ff >> in)
    {
        p[i].setX(f);
        p[i].setY(ff);
        p[i].setId(i);
        i++;
    }

     if(ind==2)
    {
        newt an;
        an.andrew(p,n);
    }
    else if(ind==3)
    {
        grahamScan sc;
        sc.Scan(p,n);
    }

}
