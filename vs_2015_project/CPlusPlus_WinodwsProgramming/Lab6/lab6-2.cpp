/*this pointer includes the address of the object, so it can be used to compare the
addresses between different objects.*/
// lab6-2.cpp
#include <iostream>
using namespace std;
const int num = 10;
class PointND
{
public:
    PointND();
    ~PointND();
    void assignValue(double v);
    void assignCoord(int *vec, int len);
    void displayPointND();
    void copyPointND(const PointND &);
private:
    int *coord;
    double value;
};
PointND::PointND()
{
    value = 0.0;
    coord = new int[num];
    for (int i = 0; i < num; i++) coord[i] = 0;
}
PointND::~PointND()
{
    delete[] coord;
}
void PointND::assignValue(double v)
{
    value = v;
}
void PointND::assignCoord(int *vec, int len)
{
    //for (int i = 0; i < len; i++)
    //    coord[i] = vec[i];
    coord = vec;
}
void PointND::displayPointND()
{
    std::cout << "(";
    for (int i = 0; i < num; i++)
    {
        std::cout << coord[i];
        if (i != num - 1)
            std::cout << ", ";
    }
    std::cout << ") = " << value << std::endl;
}
void PointND::copyPointND(const PointND &pt)
{
    if (this != &pt)
    {
        cout << "@@@" << endl;
        value = pt.value;
        coord = new int[num];
        for (int i = 0; i < num; i++) coord[i] = pt.coord[i];
    }
}
int main()
{
    int *vec = new int[num];
    for (int i = 0; i < num; i++) vec[i] = i;

    PointND pt1;
    pt1.assignValue(4.3);
    pt1.assignCoord(vec, num);
    pt1.displayPointND();

    PointND pt2;
    pt2.copyPointND(pt1);
    pt2.displayPointND();

    PointND pt3;
    pt3.copyPointND(pt3);
    pt3.displayPointND();

    delete[]vec;
    system("pause");
    return 0;
}