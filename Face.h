#ifndef FACE_H
#define FACE_H
#include "HalfEdge.h"
#include "Vertex.h"
class HalfEdge;
//!  A Basic class.
/*!
  This class contains the parameters needed by other classes
*/
class Face
{
    public:
        Face();
        HalfEdge *incidentEdge;
        bool triangulated;
};

#endif // FACE_H
