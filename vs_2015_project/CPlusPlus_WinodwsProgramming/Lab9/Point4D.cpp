#include "Point4D.h"
#include <iostream>
using namespace std;

Point4D::Point4D() : Point2D(0, 0)
{
    this->z = new int(0);
    this->t = new int(0);
}

Point4D::Point4D(int a, int b, int c, int d) : Point2D (a, b)
{
    this->z = new int(c);
    this->t = new int(d);
}

void Point4D::display() const
{
    Point2D::display();
    cout << ", z = " << *z << ", t = " << *t;
}

Point4D & Point4D::operator=(Point2D p)
{
    setXY(p.getX(), p.getY());
    return (*this);
}

void Point4D::setXY(int a, int b)
{
    Point2D::setXY(a, b);
}

