#include "Point2D.h"
#include <iostream>
using namespace std;

Point2D::Point2D()
{
    this->x = new int(0);
    this->y = new int(0);
}

Point2D::Point2D(int a, int b)
{
    this->x = new int(a);
    this->y = new int(b);
}

void Point2D::display() const
{
    cout << "x = " << *x << ", y = " << *y ;
}

void Point2D::setXY(int a, int b)
{
    *(this->x) = a;
    *(this->y) = b;
}

int Point2D::getX()
{
    return *(this->x);
}

int Point2D::getY()
{
    return *(this->y);
}
