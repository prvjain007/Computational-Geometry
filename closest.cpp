#include "closest.h"
#include <stdio.h>
#include <float.h>
#include <stdlib.h>
#include <math.h>
#include "compare.h"
#include "Point.h"
#include "jarvis.h"
#include "readWrite.h"

float closest::closestUtil(Point P[], int n)
{
    // If there are 2 or 3 points, then use brute force
    if (n <= 3)
        return bruteForce(P, n);


    int mid = n/2;
    Point midPoint = P[mid];
    float dl = closestUtil(P, mid);
    float dr = closestUtil(P + mid, n-mid);


    float d = mini(dl, dr);

    Point strip[n];
    int j = 0;
    for (int i = 0; i < n; i++)
        if (abs(P[i].x - midPoint.x) < d)
            strip[j] = P[i], j++;


    return mini(d, stripClosest(strip, j, d) );
}
float closest::closes(Point P[], int n)
{
    sortX(P, n);
    return closestUtil(P, n);
}


float closest::dist(Point p1, Point p2)
{
    return sqrt( (p1.x - p2.x)*(p1.x - p2.x) +
                 (p1.y - p2.y)*(p1.y - p2.y)
               );
}

float closest::bruteForce(Point P[], int n)
{
    float min = FLT_MAX;
    for (int i = 0; i < n; ++i)
        for (int j = i+1; j < n; ++j)
            if (dist(P[i], P[j]) < min)
                min = dist(P[i], P[j]);
    return min;
}
float closest::mini(float x, float y)
{
    return (x < y)? x : y;
}
float closest::stripClosest(Point strip[], int sizi, float d)
{
    float min = d;  // Initialize the minimum distance as d

    sortY(strip, sizi);
    for (int i = 0; i < sizi; ++i)
        for (int j = i+1; j < sizi && (strip[j].y - strip[i].y) < min; ++j)
            if (dist(strip[i],strip[j]) < min)
                min = dist(strip[i], strip[j]);

    return min;
}
