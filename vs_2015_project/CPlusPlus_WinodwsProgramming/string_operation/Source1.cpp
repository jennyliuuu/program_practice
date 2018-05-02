//#include <iostream>
//using namespace std;
//
//#define my_countof(x) (sizeof(x)/sizeof(x[0]))
//
//void modify(char *c, int a)
//{
//    c[1] = 'a';
//    int s = sizeof(c)/sizeof(c[0]);
//    cout << c << " " << my_countof(c) << " " << s << endl;  //c runtime : _countof(c) is illegal
//}
//
//void copy(char *c2, int size, char *c1)
//{
//    // sizeof(c2) will get 8 (the size of the pointer)
//    cout << "(before)c2: " <<endl;
//    strcpy_s(c2, size, c1);
//    cout << "(after)c2: " << c2 << endl;
//}
//
//void copy_truncate(char *c2, int size, char *c1)
//{
//    // sizeof(c2) will get 8 (the size of the pointer)
//    cout << "(before)c2: " << endl;
//    strncpy_s(c2, size, c1, _TRUNCATE);
//    cout << "(after)c2: " << c2 << endl;
//}
//
//int main()
//{
//    int a = 1;
//
//    //**********************************************************
//    //modify()
//    //**********************************************************
//
//    //ok
//    char c[10] = "ZZZZZZZZ";
//    c[9] = 0;
//    modify(c, a);
//
//    //ok
//    /*
//    char *c = new char[10];
//    memset(c, 'z', sizeof(c));
//    c[9] = 0;
//    modify(c, a);
//    */
//
//    // illegal : no allocate memory
//    /*
//    char *c = "abc";    
//    modify(c, a);
//    */
//
//    //**********************************************************
//    //copy()
//    //**********************************************************
//
//    char c1[20] = "aaaaabbbbbccccc";
//    char c2[20] = {0};
//    int size = sizeof(c2) / sizeof(char) ;
//    copy(c2, size, c1);
//
//
//    //**********************************************************
//    //copy_truncate()
//    //**********************************************************
//
//    char c3[20] = "aaaaabbbbbccccc";
//    char c4[10] = { 0 };
//    int size1 = sizeof(c4) / sizeof(char);
//    copy_truncate(c4, size1, c3);
//
//
//    system("pause");
//    return 0;
//}