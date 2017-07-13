#ifndef READ_WRITE_H
#define READ_WRITE_H
#include "Point.h"


//!  A readWrite class.
/*!
  This class read points from any file and writes the convex hull co-ordinates into other file it is responsible to call different algorithms
*/
class readWrite
{
    public:
        static void read(Point p[],int n, Point b[]);
        static void write(Point p[],int n, int j, Point b[]);
        static void writee(Point p[], int n, Point d[], int l, Point e[], int m);
        static void writeee(Point p[], int n, Point d[], int l, Point e[], int m);
    protected:
    private:
};

#endif // READ_WRITE_H
