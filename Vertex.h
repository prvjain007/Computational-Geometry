#ifndef VERTEX_H
#define VERTEX_H
#include "HalfEdge.h"
#include "Face.h"
#include <string>
#include <bits/stdc++.h>
using namespace std;
class HalfEdge;
//!  A Basic class.
/*!
  This class contains the parameters needed by other classes
*/
class Vertex
{
    public:
        Vertex(double x, double y);
        double x, y;
        HalfEdge *incidentEdge;
        string type;
};

#endif // VERTEX_H
