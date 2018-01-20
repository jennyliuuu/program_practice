// lab11-3-1.cpp
//#include <iostream>
//using namespace std;
//
//class Point2D
//{
//public:
//    Point2D() {
//        x = new int(0);
//        y = new int(0);
//        cout << "New X and Y" << endl;
//    }
//    virtual ~Point2D() {
//        delete x;
//        delete y;
//        cout << "Delete X and Y" << endl;
//    }
//    Point2D(int a, int b) {
//        x = new int(a);
//        y = new int(b);
//        cout << "New X and Y" << endl;
//    }
//    int getX() { return *x; }
//    int getY() { return *y; }
//    void setX(int a) { *x = a; }
//    void setY(int a) { *y = a; }
//    virtual void display() const;
//private:
//    int *x;
//    int *y;
//};
//
//void Point2D::display() const
//{
//    cout << *x << "," << *y;
//}
//
//class Shape
//{
//public:
//    virtual void draw() = 0;
//    virtual bool is_closed() = 0;
//    virtual ~Shape() {}
//protected:
//    int color;
//};
//
//class Circle : public Shape
//{
//public:
//    Circle(Point2D p, double r, int c) {
//        this->center.setX(p.getX());
//        this->center.setY(p.getY());
//        this->radius = r;
//        this->color = c;
//    }
//    void draw();
//    bool is_closed() { return true; }
//private:
//    Point2D center;
//    double radius;
//};
//
//void Circle::draw() {
//    cout << "Color: " << color << endl
//        << "Center: " << center.getX() << ", " << center.getY() << endl
//        << "Radius: " << radius << endl;
//}
//
//int main()
//{
//    Point2D pt(3, 4);
//    Circle c(pt, 5, 255);
//    c.draw();
//    system("pause");
//    return 0;
//}