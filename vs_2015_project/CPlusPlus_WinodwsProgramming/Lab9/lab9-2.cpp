//#include <iostream>
//using std::cout; using std::endl;
//
//class Point2D
//{
//public:
//    Point2D(int n1 = 0, int n2 = 0) :x(n1), y(n2) {}
//    void display() const;
//private:
//    int x;
//    int y;
//};
//void Point2D::display() const
//{
//    cout << x << "," << y;
//}
//class Point4D : public Point2D
//{
//public:
//    Point4D(int n1 = 0, int n2 = 0, int n3 = 0, int n4 = 0) :Point2D(n1, n2), z(n3), t(n4) {}
//    void display() const;
//private:
//    int z;
//    int t;
//};
//void Point4D::display() const
//{
//    Point2D::display();
//    cout << "," << z << "," << t;
//}
//class Car : public Point4D
//{
//    public:
//        Car(int n1 = 0, int n2 = 0, int n3 = 0, int n4 = 0) : Point4D(n1, n2, n3, n4)
//        {
//            color = 0;
//            year = 0;
//        }
//        // copy constructor
//        Car(const Point4D &p) : Point4D(p) 
//        {
//            color = 0; year = 0;
//        }
//        void display() const;
//        void setColor(const int c) { color = c; }
//        void setYear(const int y) { year = y; }
//    private:
//        int color;
//        int year;
//};
//void Car::display() const
//{
//    cout << "color: " << color << endl;
//    cout << "year: " << year << endl;
//    Point4D::display();
//}
//int main()
//{
//    Point4D pt4(1, 2, 3, 4);
//    Car c1(pt4);
//    c1.setColor(128);
//    c1.setYear(2011);
//    c1.display(); cout << endl;
//    system("pause");
//    return 0;
//}