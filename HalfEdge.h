#ifndef HALFEDGE_H
#define HALFEDGE_H
#include "Vertex.h"
#include "Face.h"

class Face;
class Vertex;
//!  A Basic class.
/*!
  This class contains the Half Edge
*/
class HalfEdge
{
    public:
    HalfEdge();
    Vertex *incidentVertex, *helper;
    Face *incidentFace;
    HalfEdge *prev, *next, *twin;
};

#endif // HALFEDGE_H

