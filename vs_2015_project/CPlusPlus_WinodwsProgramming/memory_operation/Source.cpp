#include <iostream>
using namespace std;

class memOperation
{
public:
    memOperation(void): a(0), b(0){};
    int a;
    int b;
    char c;
    char d[8];
    int e;
};

int main()
{
    int arrA[2];
    int arrB[2];
    cout << "The location of arrA and arrB:" << endl;
    cout << "arrA: 0x" << arrA << "\narrB: 0x" << arrB << endl << endl;

    memOperation memOper1;
    memOper1.a = 10;
    memOper1.b = 20;
    memOper1.c = 'a';
    memOper1.d[0] = 'a';
    memOper1.d[1] = 'b';
    memOper1.d[2] = '\0';
    memOper1.e = 30;

    cout << "value:" << endl;
    cout << "memOper1.a: "<< memOper1.a << ", memOper1.b: " << memOper1.b << ", memOper1.c: " << memOper1.c 
        << ", memOper1.d: " << memOper1.d << ", memOper1.e: " << memOper1.e << endl << endl;

    cout << "location:" << endl;
    printf("memOper1.a: %p, memOper1.b: %p, memOper1.c: %p, memOper1.d: %p, memOper1.e: %p \n\n", 
            &memOper1.a, &memOper1.b, &memOper1.c, &memOper1.d, &memOper1.e);

    char test = 't';
    printf("location of test: %p\n\n", &test);

    system("pause");
}