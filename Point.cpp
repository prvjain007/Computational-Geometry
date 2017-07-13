#include "Point.h"
#include <iostream>
using namespace std;
//! A normal member taking one arguments and returning void. This function enters X Co-ordinate of Point.
/*!
  \param xx X Co-ordinate.
*/
void Point::setD(bool b)
{
    dir=b;
}
float Point::getD()
{
    return dir;
}
void Point:: setX(float xx)
{
    x=xx;
}
//! A normal member taking one arguments and returning void. This function enters Y Co-ordinate of Point.
/*!
  \param yy Y Co-ordinate.
*/
void Point:: setY(float yy)
{
    y=yy;
}
//! A normal member taking no argument and returning X Co-ordinate of Point.
/*!
  \return  x X Co-ordinate.
*/
float Point::getX()
{
    return x;
}
//! A normal member taking no argument and returning Y Co-ordinate of Point.
/*!
  \return  y Y Co-ordinate.
*/
float Point::getY()
{
    return y;
}
//! A normal member taking one argument and returning void. This function enters ID of Point.
/*!
  \param ii ID.
*/
void Point:: setId(int ii)
{
    id=ii;
}
//! A normal member taking no argument and returning ID of Point.
/*!
  \return  id ID.
*/
int Point::getId()
{
    return id;
}

