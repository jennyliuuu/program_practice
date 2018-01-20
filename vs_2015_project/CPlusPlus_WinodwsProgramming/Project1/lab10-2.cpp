// lab10-2
#include <iostream>
using namespace std;
class Point2D
{
    public:
        Point2D() { x = 0; y = 0; }
        void display() const;
        void setX(int a) { x = a; }
        void setY(int b) { y = b; }
        int getX() { return x; }
        int getY() { return y; }
    // ...
    private:
        int x;
        int y;
};
void Point2D::display() const
{

}

class Circle
{
    public:
        Circle();
        void draw();
        void setCR(Point2D, double);
        // ...
    private:
        Point2D center;
        double radius;
};
Circle::Circle()
{
    center.setX(0);
    center.setY(0);
    radius = 0;
}
void Circle::draw()
{
    cout << "center = " << center.getX() << "," << center.getY() << endl;
    cout << "radius = " << radius << endl;
}

void Circle::setCR(Point2D p, double d)
{
    center = p;
    radius = d;
}

class Triangle
{
    public:
        Triangle();
        ~Triangle() { delete[] vertices; }
        void draw();
        void set_vertices(Point2D*);
    private:
        Point2D *vertices;
};
Triangle::Triangle()
{
    vertices = new Point2D[3];
    vertices[0].setX(0);
    vertices[0].setY(0);
    vertices[1].setX(0);
    vertices[1].setY(0);
    vertices[2].setX(0);
    vertices[3].setY(0);
}
Triangle::Triangle(Point2D *, int)
{
}
void Triangle::draw()
{
    cout << "vertices:" << endl
        << vertices[0].getX() << "," << vertices[0].getY() << endl
        << vertices[1].getX() << "," << vertices[1].getY() << endl
        << vertices[2].getX() << "," << vertices[2].getY() << endl;
}

void Triangle::set_vertices(Point2D* p)
{
    vertices = p;
}

class Circle_in_Triangle : public Circle, public Triangle
{
    public:
        Circle_in_Triangle(Point2D, double d, Point2D *);
        void draw()
        {
            Circle::draw();
            Triangle::draw();
        }
    private:
        Circle c;
        Triangle t;
};
Circle_in_Triangle::Circle_in_Triangle(Point2D p, double d, Point2D *vec)
{
    c.setCR(p, d);
    t.set_vertices(vec);
}
int main()
{
    Point2D p;
    Point2D *vec = new Point2D[3];
    Circle_in_Triangle ct(p, 0, vec);
    ct.draw();
    system("pause");
    return 0;
}


