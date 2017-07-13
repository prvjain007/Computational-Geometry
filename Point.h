#ifndef POINT_H
#define POINT_H

//!  A Point class.
/*!
  This class contains the X,Y co-ordinates along with the unique ID of each Point
*/
class Point
{
    public:

        void setX(float x);
        void setY(float y);
        float getX();
        float getY();
        void setD(bool b);
        float getD();


        void setId(int x);
        int getId();

        float x;//! A float.
    /*! X co-ordinate of float */
        float y;//! A float.
    /*! Y co-ordinate of float */
        int id;//! An int.
    /*! ID of particular point */
        bool dir;
};

#endif // POINT_H
