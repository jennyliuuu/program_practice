/*Class Polygon is also an abstract class since it has pure virtual functions
draw(), which are inherited from its base class Shape but have not been
defined. Thus objects of Polygon cannot be created. However, Triangle is
no longer an abstract class since it does not contain any pure virtual
functions.*/


#include <iostream>
using namespace std;

class Point2D
{
public:
    Point2D() {
        x = new int(0);
        y = new int(0);
        cout << "New X and Y" << endl;
    }
    virtual ~Point2D() {
        delete x;
        delete y;
        cout << "Delete X and Y" << endl;
    }
    Point2D(int a, int b) {
        x = new int(a);
        y = new int(b);
        cout << "New X and Y" << endl;
    }
    int getX() { return *x; }
    int getY() { return *y; }
    void  setPoint2D(int, int);
    virtual void display() const;
private:
    int *x;
    int *y;
};
void Point2D::display() const
{
    cout << *x << "," << *y;
}
void Point2D::setPoint2D(int a, int b)
{
    *x = a;
    *y = b;
}

class Shape
{
public:
    virtual void draw() = 0;
    virtual bool is_closed() = 0;
    virtual ~Shape() {}
protected:
    int color;
};
class Polygon : public Shape
{
public:
    bool is_closed() { return true; }
};
class Triangle : public Polygon
{
public:
    Triangle(Point2D*, int);
    ~Triangle() { delete[] vertices; }
    void draw();
private:
    Point2D *vertices;
};
Triangle::Triangle(Point2D* p, int a)
{
    vertices = p;
    color = a;
}
void Triangle::draw()
{
    cout << "color: " << color << endl
        << "vertices: " << endl;
    for (int i = 0; i < 3; i++)
        cout << vertices[i].getX() << ", " << vertices[i].getY() << endl;
}
int main()
{
    Point2D *vec = new Point2D[3];
    vec[0].setPoint2D(1, 1);
    vec[1].setPoint2D(6, 1);
    vec[2].setPoint2D(1, 8);
    Triangle t(vec, 255);
    
    t.draw(); delete[]vec;
    system("pause");
    return 0;
}

