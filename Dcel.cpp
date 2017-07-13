#include <bits/stdc++.h>
#include "Dcel.h"
using namespace std;

#define mp make_pair
//! A Constructor
/*!
  \param vec pair of points

*/
Dcel::Dcel(vector<pair<double, double> > vec)
{
    initialFace=new Face();
    initialFace->triangulated=0;
    outer=new Face();
    outer->triangulated=1;
    initialVertex=new Vertex(vec[0].first, vec[0].second);
    initialEdge=new HalfEdge();
    initialVertex->incidentEdge=initialEdge;
    initialEdge->incidentVertex=initialVertex;
    initialEdge->incidentFace=initialFace;
    initialFace->incidentEdge=initialEdge;
    initialTwin=new HalfEdge();
    initialEdge->twin=initialTwin;
    initialTwin->twin=initialEdge;
    initialTwin->incidentFace=outer;
    outer->incidentEdge=initialTwin;
    Vertex *lastVertex=initialVertex;
    HalfEdge *lastEdge=initialEdge;
    HalfEdge *lastTwin=initialTwin;
    for(int i=1; i<vec.size(); i++)
    {
        HalfEdge *he=new HalfEdge();
        Vertex *v=new Vertex(vec[i].first, vec[i].second);
        v->incidentEdge=he;
        he->incidentVertex=v;
        he->prev=lastEdge;
        lastEdge->next=he;
        lastTwin->incidentVertex=v;
        he->incidentFace=initialFace;

        HalfEdge *tw=new HalfEdge();
        tw->incidentFace=outer;
        he->twin=tw;
        tw->twin=he;
        tw->next=lastTwin;
        lastTwin->prev=tw;

        lastEdge=he;
        lastTwin=tw;
        lastVertex=v;

        if(i==(vec.size()-1))
        {
            tw->incidentVertex=initialVertex;
            he->next=initialEdge;
            initialEdge->prev=he;
            tw->prev=initialTwin;
            initialTwin->next=tw;
        }
    }

    HalfEdge* h=initialEdge;
    do
    {
        vecc.push_back(h);
        h=h->next;
    }while(h!=initialEdge);
}


//! A functions to add edges
/*!
  \param e1 Vertex A
  \param e2 Vertex B
  \return nothing
*/

void Dcel::addEdge(Vertex *v1, Vertex *v2)
{
    cout<<"added edge ("<<(v1->x)<<","<<(v1->y)<<") and ("<<(v2->x)<<","<<(v2->y)<<")"<<endl;
    HalfEdge *v1edge=v1->incidentEdge;
    HalfEdge *v2edge=v2->incidentEdge;
    HalfEdge *v1first=v1->incidentEdge;
    HalfEdge *v2first=v2->incidentEdge;

    if(v1edge==v1first)
    //cout<<"hi"<<endl;
    do
    {
        //cout<<"hi"<<endl;
        v2edge=v2first;
        do
        {

            if(v1edge->incidentFace == v2edge->incidentFace)
            goto label;
            v2edge=(v2edge->prev)->twin;
        }while(v2edge!=v2first);
        v1edge=(v1edge->prev)->twin;
    }while(v1edge!=v1first);

    label:
    //cout<<"hi"<<endl;
    HalfEdge *he=new HalfEdge();
    HalfEdge *tw=new HalfEdge();
    Face *f=new Face();
    f->triangulated=0;

    //cout<<"hi"<<endl;
    he->incidentVertex=v1;
    //cout<<"hi"<<endl;
    he->next=v2edge;
    //cout<<"hi"<<endl;
    he->prev=v1edge->prev;

    //cout<<"hi"<<endl;
    tw->incidentVertex=v2;
    tw->next=v1edge;
    tw->prev=v2edge->prev;

    //cout<<"hi"<<endl;
    (v2edge->prev)->next=tw;
    v2edge->prev=he;
    (v1edge->prev)->next=he;
    v1edge->prev=tw;

    he->twin=tw;
    tw->twin=he;

    if((v2edge->incidentFace)!=initialFace)
    {
        HalfEdge* hh=he;
        do
        {
            hh->incidentFace=f;
            hh=hh->next;
        }while(hh!=he);
        tw->incidentFace=v1edge->incidentFace;
        f->incidentEdge=he;
        (v1edge->incidentFace)->incidentEdge=tw;
    }

    else
    {
        HalfEdge *h=initialEdge;
        do
        {
            if(h==he)
            {
                HalfEdge* hh=tw;
                do
                {
                    hh->incidentFace=f;
                    hh=hh->next;
                }while(hh!=tw);
                he->incidentFace=initialFace;
                f->incidentEdge=tw;
                goto label2;
            }

            if(h==tw)
            {
                HalfEdge* hh=he;
                do
                {
                    hh->incidentFace=f;
                    hh=hh->next;
                }while(hh!=he);
                tw->incidentFace=initialFace;
                f->incidentEdge=he;
                goto label2;
            }

            h=h->next;
        }while(h!=initialEdge);
    }
    label2:;
}

//! A functions taking three arguments for orientation
/*!
  \param e1 Vertex A
  \param e2 Vertex B
  \return boolean gives direction
*/


bool Dcel::left(pair<double, double> p, pair<double, double> q, pair<double, double> r)
{
    double val = (double)((q.second - p.second) * (r.first - q.first)) - (double) ((q.first - p.first) * (r.second - q.second));
    return (val > 0)? 0:1;
}


//! A function for making it monotone
/*!
  \param e1 Point A
  \param e2 Point B
  \return boolean which compares
*/

void Dcel::makeMonotone()
{
    cout<<"making monotone:"<<endl;


    deque<Vertex*> pq;

    //finding types of vertices:
    int n=0;
    Vertex *v=initialVertex;
    do
    {
        pq.push_back(v);
        n++;
        double x1=(((v->incidentEdge)->prev)->incidentVertex)->x;
        double y1=(((v->incidentEdge)->prev)->incidentVertex)->y;
        double x2=v->x;
        double y2=v->y;
        double x3=(((v->incidentEdge)->next)->incidentVertex)->x;
        double y3=(((v->incidentEdge)->next)->incidentVertex)->y;

        if((y1<y2 && y2<y3) || (y1>y2 && y2>y3))
            {v->type="regular";}
        else if(y2>y1)
        {
            if(x2>x1) {v->type="split";}
            else {v->type="start";}
        }
        else
        {
            if(x2>x1) {v->type="end";}
            else {v->type="merge";}
        }
        v=((v->incidentEdge)->next)->incidentVertex;
    }while(v!=initialVertex);

    sort(pq.rbegin(), pq.rend());

    //making monotone:
    while(!pq.empty())
    {
        Vertex *vr=pq.front();
        if(vr->type == "start") {handleStartVertex(vr);}
        else if(vr->type == "end") {handleEndVertex(vr);}
        else if(vr->type == "split") {handleSplitVertex(vr);}
        else if(vr->type == "merge") {handleMergeVertex(vr);}
        else {handleRegularVertex(v);}
        pq.pop_front();
    }
}


//! A function for finding left edges
/*!
  \param e1 Vertex
*/

HalfEdge* Dcel::findLeftEdge(Vertex *v)
{
    double dist=numeric_limits<double>::max();
    HalfEdge *hetoleft;
    for(set<HalfEdge*>::iterator it=status.begin(); it!=status.end(); it++)
    {
        HalfEdge *he=*it;
        Vertex *v1=he->incidentVertex;
        Vertex *v2=(he->next)->incidentVertex;
        double x1=v1->x;
        double y1=v1->y;
        double x2=v2->x;
        double y2=v2->y;
        double xx=v->x;
        double yy=v->y;
        if(left(mp(x1, y1), mp(x2, y2), mp(xx, yy)))
        {
            double d;
            if(x1>x2)
            {
                d=(xx-x1)+(y1-yy)*(x1-x2)/(y1-y2);
                if(d<dist) hetoleft=he;
            }
            else
            {
                d=(xx-x2)+(yy-y2)*(x2-x1)/(y1-y2);
                if(d<dist) hetoleft=he;
            }
        }
    }

    return hetoleft;
}


//! A comparing function for handling starting vertex
/*!
  \param e1 HandlingStartingVertex
*/

void Dcel::handleStartVertex(Vertex *v)
{
    cout<<"in start"<<endl;
    status.insert(v->incidentEdge);
    v->incidentEdge->helper=v;
}



//! A comparing function for handling ending vertex
/*!
  \param e1 HandlingStartingVertex
*/
void Dcel::handleEndVertex(Vertex *v)
{
    cout<<"in end"<<endl;
    if((((v->incidentEdge)->prev)->helper)->type == "merge")
        addEdge(v, ((v->incidentEdge)->prev)->helper);
    status.erase((v->incidentEdge)->prev);
}



//! A comparing function for splitting starting vertex
/*!
  \param e1 Handling Splitting Vertex
*/
void Dcel::handleSplitVertex(Vertex *v)
{
    cout<<"in split"<<endl;
    HalfEdge *hetoleft=findLeftEdge(v);
    addEdge(hetoleft->helper, v);
    hetoleft->helper=v;
    status.insert(v->incidentEdge);
    v->incidentEdge->helper=v;
}


//! A  function for handling merge vertex
/*!
  \param e1 Handling mergeVertex
*/

void Dcel::handleMergeVertex(Vertex *v)
{
    cout<<"in merge"<<endl;
    if((((v->incidentEdge)->prev)->helper)->type == "merge")
        addEdge(v, ((v->incidentEdge)->prev)->helper);
    status.erase((v->incidentEdge)->prev);
    HalfEdge *hetoleft=findLeftEdge(v);
    if((hetoleft->helper)->type == "merge")
        addEdge(v, hetoleft->helper);
    hetoleft->helper=v;
}


//! A  function for handling regular vertex
/*!
  \param e1 Handling Vertex
*/

void Dcel::handleRegularVertex(Vertex *v)
{
    cout<<"in regular"<<endl;
    double thisy=v->y;
    double nexty=(((v->incidentEdge)->next)->incidentVertex)->y;
    if(nexty<thisy)
    {
        if((((v->incidentEdge)->prev)->helper)->type == "merge")
        addEdge(v, ((v->incidentEdge)->prev)->helper);
        status.erase((v->incidentEdge)->prev);
        status.insert(v->incidentEdge);
        v->incidentEdge->helper=v;
    }
    else
    {
        HalfEdge *hetoleft=findLeftEdge(v);
        if((hetoleft->helper)->type == "merge")
            addEdge(v, hetoleft->helper);
        hetoleft->helper=v;
    }
}



int Dcel::orientation(pair<Vertex*, int> a, pair<Vertex*, int> b, pair<Vertex*, int> c)
{
    //calculate determinant:
double det=((b.first->x)-(a.first->x))*((c.first->y)-(a.first->y)) - ((b.first->y)-(a.first->y))*((c.first->x)-(a.first->x));
if(det<0)       return 1; //clockwise
else if(det>0)  return 2; //counter-clockwise
else            return  0; //collinear
}


//! A  function for triangulating polygon
/*!

*/
void Dcel::triangulatePolygon()
{

    triangulatePolygon(initialEdge, 0);
}

//! A  function for triangulating polygon
/*!
  \param e1 Half edge
  \param turn integer
*/
void Dcel::triangulatePolygon(HalfEdge *he, int turn)
{

        triangulateMonotonePolygon(he);

    if(turn==(vecc.size()-1)) return;
    triangulatePolygon(vecc[turn+1], turn+1);
}


//! A  function for triangulating monotone polygon
/*!
  \param e1 Half edge
*/
void Dcel::triangulateMonotonePolygon(HalfEdge *he)
{
    cout<<"triangulating monotone polygon:"<<endl;
    vector<pair<Vertex*, int> > vec;

    HalfEdge *h=he;
    vector<HalfEdge*> edges_of_polygon;
    do
    {
        edges_of_polygon.push_back(h);
        vec.push_back(make_pair(h->incidentVertex, 1));
        h=h->next;
    }while(h!=he);
    if(vec.size()==3)
    {
        he->incidentFace->triangulated=1;
        return;
    }

    double least_y=vec[0].first->y;
    vector<pair<Vertex*, int> >::iterator least=vec.begin();
    for(vector<pair<Vertex*, int> >::iterator it=vec.begin()+1; it!=vec.end(); it++)
    {
        double yy=it->first->y;
        if(yy<least_y)
        {
            least_y=yy;
            least=it;
        }
    }
    //vector<pair<Vertex*, int> >::iterator leastt=least;


    while(((least+1)->first->y) > (least->first->y))
    {
        least->second=2;
        if(least==vec.end()-2)
        {
            if(((vec.end()-1)->first->y) < (vec.begin()->first->y))
            {
                (least+1)->second=2;
                least=vec.begin();
            }
            else break;
        }
        else least=least+1;
    }

    pair<Vertex*, int> p=*(vec.begin());
    /*vec[0]=*leastt;
    vec[leastt-vec.begin()]=p;
    */

    sort(vec.rbegin(), vec.rend());


    int sec_side=vec[1].second;
    vec[0].second=sec_side;
    sec_side=vec[vec.size()-2].second;
    vec[vec.size()-1].second=sec_side;
    stack<pair<Vertex*, int> > stk;
    stk.push(vec[0]);
    stk.push(vec[1]);

    for(int i=2; i<vec.size(); i++)
    {
        bool same= (stk.top().second == vec[i].second);
        if(same)
        {
            pair<Vertex*, int> last=stk.top();
            stk.pop();
            int side=vec[i].second;
            while(stk.size()!=1)
            {
                p=stk.top();
                int orien=orientation(vec[i], last, p);
                if(orien==side)
                {
                    addEdge(vec[i].first, p.first);
                    last=p;
                    stk.pop();
                }
                else break;
            }
            if(i!=vec.size()-1)
            {
                p=stk.top();
                int orien=orientation(vec[i], last, p);
                if(orien==side)
                {
                    addEdge(vec[i].first, p.first);
                    last=p;
                    stk.pop();
                }
            }
            stk.push(last);
        }
        else
        {
            for(int j=0; j<stk.size()-1; j++)
            {
                p=stk.top();
                stk.pop();
                addEdge(vec[i].first, p.first);
            }
            stk.pop();
            stk.push(vec[i-1]);
            stk.push(vec[i]);
        }
    }

    //he->incidentFace->triangulated=1;
    for(vector<HalfEdge*>::iterator it=edges_of_polygon.begin(); it!=edges_of_polygon.end(); it++)
    {
        (*it)->incidentFace->triangulated=1;
    }
}
