#pragma once
#ifndef POINT4D_H
#define POINT4D_H
#include "Point2D.h"
class Point4D : public Point2D
{
    public:
        Point4D();
        Point4D(int, int, int, int);
        void display() const;
        Point4D& operator = (Point2D);
        void setXY(int, int);
    private:
        int *z;
        int *t;
};
#endif
