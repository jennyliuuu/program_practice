/*
#include <iostream>
using namespace std;

class class_A
{
public:
    //class_A() { a = new class_A(); }   //will crash
    class_A() { a = new int(); }
    ~class_A() 
    { 
        cout << "delete" << endl; 
        delete a;  //call the destructor of a
    }
private:
    //class_A *a;
    int *a;
};


int main()
{
    class_A *test = new class_A();
    delete test;

    system("pause");
    return 0;
}
*/