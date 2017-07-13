#ifndef BASIC_H
#define BASIC_H
#include "Point.h"

class Basic : public Point
{
    public:
        Basic();
        void setboth(float x, float y);
    protected:
    private:
        Point p;
};

#endif // BASIC_H
