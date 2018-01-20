//// lab9-1-1.cpp
//#include <iostream>
//using std::cout; using std::endl;
//
//class Point2D
//{
//    public:
//	    Point2D(int n1 = 0, int n2 = 0) :x(n1), y(n2) {}
//	    void display() const;
//    private:
//	    int x;
//	    int y;
//};
//void Point2D::display() const
//{
//	cout << x << "," << y;
//}
//class Point4D : public Point2D
//{
//    public:
//	    Point4D(int n1 = 0, int n2 = 0, int n3 = 0, int n4 = 0) :Point2D(n1, n2), z(n3), t(n4) {}
//	    void display() const;
//    private:
//	    int z;
//	    int t;
//};
//void Point4D::display() const
//{
//	Point2D::display();
//	cout << "," << z << "," << t;
//}
//int main()
//{
//	Point4D pt(1, 2, 3, 4);
//	pt.display();
//    system("pause");
//	return 0;
//}