#include <iostream>
#include <string>
#include <tchar.h>
using namespace std;

int main()
{
    /*
    // 3 way to initialize
    wchar_t wc1[11] = { 0 };
    wchar_t wc2[11] = { '\0' };
    wchar_t wc3[11] = L"";
    cout << wc1[1] << "~ " << wc2[1] << "~ " << wc3[1] <<endl;

    char c1[11] = { 0 };
    char c2[11] = { '\0' };
    char c3[11] = "";
    cout << c1[0] << "~ " << c2[0] << "~ " << c3[0] << endl;
    */
//========================================================================================
    /*
    // operation of wstring
    wstring acCode = L"AAAAABBBBBCCCCC";
    wcout << acCode << endl;
    acCode.replace(5, 10, L"XXXXXXXXXX");
    wcout << acCode << endl;
    */
//========================================================================================
    /*
    //memset()
    char c1[11] = "aaaaabbbbb";
    cout << "(before)c1: " << c1 << endl;

    memset(c1 + 5, 'c', 5);
    cout << "(after)c1: " << c1 << endl;
    */
//========================================================================================
    /*
    //wmemcpy(),wcslen()
    wchar_t a[6] = L"aaaaa", b[6] = {0}, c[6] = {0};
    wcout << "a= " << a << ", b= " << b << endl;

    wmemcpy(b, a, wcslen(a));
    wcout << "a= " << a << ", b= " << b << endl;
    */
//========================================================================================
    /*
    //wmemcpy(),wmemset()
    wstring ws = L"aaaaabbbbb";
    wchar_t wc[11] = {0};
    wcout << "ws: " << ws << ", wc: " << wc << endl;

    wmemcpy(wc, ws.c_str(), wcslen(ws.c_str()));
    wcout << "ws: " << ws << ", wc: " << wc << endl;

    wmemset(wc+5, 'c', wcslen(wc)-5);
    wcout << "ws: " << ws << ", wc: " << wc << endl;
    */
//========================================================================================
    /*
    TCHAR szAC[24] = _T("aaaaa-bbbbb-ccccc-ddddd");
    TCHAR _szAC[24] = _T("");

    memcpy(_szAC, szAC, _tcslen(szAC));
    cout << _tcslen(szAC) << " " << strlen(_szAC) << " ~~" << _szAC << endl;

    memset(_szAC + 5, _T('X'), _tcslen(_szAC) - 5);
    // the same as
    //for (int i = 5; i < _tcslen(szAC); i++)
    //    if (_szAC[i] != '-') _szAC[i] = _T('X');

    cout << _tcslen(szAC) << " " << _tcslen(_szAC) << " ~~" << _szAC << endl;
    */
//========================================================================================
    /*
    // use wcscpy_s()/memcpy() is more secure
    // use wcscpy_s() for wchar_t is better
    wchar_t a[1023] = L"aaaaa", b[1023] = { 0 };
    wcout << "a= " << a << ", b= " << b << endl;

    wcscpy_s(b, sizeof(a) / sizeof(wchar_t), a);  // the same as: memcpy(b, a, sizeof(a) / sizeof(wchar_t));

    wcout << "a= " << a << ", b= " << b << ", wcslen(a)="<< wcslen(a) << ", sizeof(a)=" << sizeof(a) << endl;
    cout << "sizeof(wchar_t)=" << sizeof(wchar_t) << ", sizeof(a)/sizeof(wchar_t)=" << sizeof(a) / sizeof(wchar_t) << endl;
    cout << "sizeof(a[0])=" << sizeof(a[0]) << ", sizeof(a)/sizeof(a[0])=" << sizeof(a) / sizeof(a[0]) << endl;
    */
//========================================================================================
    /*
    // memcpy() for wchar_t is ok but not good
    wstring ws = L"aaaaabbbbbccccc";
    wchar_t wc[1024] = { 0 };
    wcout << "ws: " << ws << ", wc: " << wc << endl;
    
    memcpy(wc, ws.c_str(), wcslen(ws.c_str()) * sizeof(wchar_t));   //the same as : memcpy(wc, ws.c_str(), sizeof(wc) / sizeof(wchar_t));
    wcout << "ws: " << ws << ", wc: " << wc << endl;
    wcout << "wc+5 = " << wc + 5 << ", wcslen(wc)- 5 = " << wcslen(wc) - 5 << endl;

    //memset() for wchat_t doesn't work!!
    //memset(wc + 5*sizeof(wchar_t), 'c', sizeof(wc) / sizeof(wchar_t) - 5*sizeof(wchar_t));
    //memset(wc + 5, L'c', sizeof(wc) / sizeof(wchar_t) - 5 * sizeof(wchar_t));
    //memset(wc , L'c', sizeof(wc) / sizeof(wchar_t));
    
    for (int i = 5; i < wcslen(wc); i++)
        wc[i] = L'c';

    wcout << wc << endl;
    */

    system("pause");

    return 0;
}