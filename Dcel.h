#ifndef DCEL_H
#define DCEL_H
#include "Face.h"
#include "Vertex.h"
#include "HalfEdge.h"
#include <bits/stdc++.h>
#include "Compare.h"
using namespace std;
//!  A DCEL class.
/*!
  This class contains the functions which are needed by other classes
*/
class Dcel
{
    public:
    Dcel(vector<pair<double, double> > vec);
    Vertex *initialVertex;
    HalfEdge *initialEdge;
    HalfEdge *initialTwin;
    Face *initialFace;
    Face *outer;
    set<HalfEdge*> status;
    vector<HalfEdge*> vecc;
    void addEdge(Vertex *v1, Vertex *v2);
    bool left(pair<double, double> p, pair<double, double> q, pair<double, double> r);
    void makeMonotone();
    HalfEdge* findLeftEdge(Vertex *v);
    void handleStartVertex(Vertex *v);
    void handleEndVertex(Vertex *v);
    void handleSplitVertex(Vertex *v);
    void handleMergeVertex(Vertex *v);
    void handleRegularVertex(Vertex *v);
    int orientation(pair<Vertex*, int> a, pair<Vertex*, int> b, pair<Vertex*, int> c);
    void triangulatePolygon();
    void triangulatePolygon(HalfEdge *he, int turn);
    void triangulateMonotonePolygon(HalfEdge *he);
    protected:
    private:
};

#endif // DCEL_H
