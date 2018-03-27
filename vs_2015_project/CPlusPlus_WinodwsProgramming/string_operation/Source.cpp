#include <iostream>
#include <string>
#include <tchar.h>
#include "windows.h"
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
    wstring acCode = L"AAAAABBBBBCCCCC", acCode1 = L"";
    wcout << acCode << endl;
    //acCode.replace(5, 10, L"XXXXXXXXXX");
    //wcout << acCode << endl;
    acCode1 = acCode;
    wcout << acCode1[0] << " " << acCode1[5] << endl;


    printf("~~%ls\n", acCode1.c_str());  // use printf for wstring: need %ls and c_str()
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

    wcout << "a= " << a << ", b= " << b << ", wcslen(b)=" << wcslen(b) << ", sizeof(b)=" << sizeof(b) << endl;
    //wcscpy_s(b, sizeof(b) / sizeof(wchar_t), a);  // ok (osce)  wcscpy_s(): number of length to copy?
    //wcscpy_s(b, wcslen(b)+1, a);     //ok
    memcpy(b, a, wcslen(a) * sizeof(wchar_t));  //ok  (osce)   memcpy(): Number of bytes to copy
    //memcpy(b, a, sizeof(a) / sizeof(wchar_t));   //ok, but not good
    

    wcout << "a= " << a << ", b= " << b << ", wcslen(b)="<< wcslen(b) << ", sizeof(b)=" << sizeof(b) << endl;
    //cout << "sizeof(wchar_t)=" << sizeof(wchar_t) << ", sizeof(a)/sizeof(wchar_t)=" << sizeof(a) / sizeof(wchar_t) << endl;
    //cout << "sizeof(a[0])=" << sizeof(a[0]) << ", sizeof(a)/sizeof(a[0])=" << sizeof(a) / sizeof(a[0]) << endl;
    */
//========================================================================================
    /*
    // memcpy(): Number of bytes to copy
    // memcpy() for wchar_t is ok but not good
    wstring ws = L"aaaaabbbbbccccc";
    wchar_t wc[1024] = { 0 };
    wcout << "ws: " << ws << ", wc: " << wc << endl;
    
    memcpy(wc, ws.c_str(), wcslen(ws.c_str()) * sizeof(wchar_t));   //not good : memcpy(wc, ws.c_str(), sizeof(wc) / sizeof(wchar_t));
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

//========================================================================================
/*
    // ref: http://www.cnblogs.com/goed/archive/2011/11/11/2245702.html
    const int BUFSIZE = 2048;
    LPCTSTR sAC = _T("aaaaabbbbbccccc");
    TCHAR szACTemp[BUFSIZE + 2] = _T("");
    cout << "sAC: " << sAC << endl << "szACTemp:" << szACTemp << endl;
    cout << "_tcslen(sAC): " << _tcslen(sAC) << endl << "_tcslen(szACTemp):" << _tcslen(szACTemp) << endl;

    cout << "==========================================" << endl;

    memcpy(szACTemp, sAC, (_tcslen(sAC) + 1) * sizeof(TCHAR));
    int nLength = _tcslen(sAC);
    for (int i = 8; i < nLength; i++)
    {
        szACTemp[i] = _T('X');
    }
    cout << "sAC: " << sAC << endl << "szACTemp:" << szACTemp << endl;
    cout << "_tcslen(sAC): " << _tcslen(sAC) << endl << "_tcslen(szACTemp):" << _tcslen(szACTemp) << endl;
    */
//===
/*
    const int BUFSIZE = 2048;
    TCHAR test[BUFSIZE + 2] = _T("aaaaabbbbbccccc");
    LPCTSTR sAC = test;
    TCHAR szACTemp[BUFSIZE + 2] = _T("");
    cout << "sAC: " << sAC << endl << "szACTemp:" << szACTemp << endl;
    cout << "_tcslen(sAC): " << _tcslen(sAC) << endl << "_tcslen(szACTemp):" << _tcslen(szACTemp) << endl;

    //sAC[3] = _T('w');    //illegal

    cout << "==========================================" << endl;
    
    memcpy(szACTemp, sAC, (_tcslen(sAC) + 1) * sizeof(TCHAR));
    int nLength = _tcslen(sAC);
    for (int i = 8; i < nLength; i++)
    {
        szACTemp[i] = _T('X');
    }
    cout << "sAC: " << sAC << endl << "szACTemp:" << szACTemp << endl;
    cout << "_tcslen(sAC): " << _tcslen(sAC) << endl << "_tcslen(szACTemp):" << _tcslen(szACTemp) << endl;
    */

    //==================================================
    cout << "===================================================" << endl;
    char ac[20] = {0};
    cout << strlen(ac) << " " << sizeof(ac) << endl;
    if (ac[0])
        cout << "ac is null" << endl;
    else
        cout << "ac is not null" << endl;


    //==================================================

    wchar_t aa[102] = {0}, bb[1023] = {0};

    wcout << "aa= " << aa << ", bb= " << bb << ", wcslen(bb)=" << wcslen(bb) << ", sizeof(bb)=" << sizeof(bb) << endl;
    wcscpy_s(bb, sizeof(bb) / sizeof(wchar_t), aa);  // ok (osce)  wcscpy_s(): number of length to copy?
    memcpy(bb, aa, wcslen(aa) * sizeof(wchar_t));  //ok  (osce)   memcpy(): Number of bytes to copy

    //==================================================

    //ref one note

    wchar_t aa1[1023] = L"aaaaabbbbbccccc", bb1[1023] = {0};
    memcpy(bb1, aa1, 16*sizeof(wchar_t));
    wcout << "aa1= " << aa1 << ", bb1= " << bb1 << ", wcslen(bb1)=" << wcslen(bb1) << ", sizeof(bb1)=" << sizeof(bb1) << endl;
    bb1[11] = L'\0';
    wcout << "aa1= " << aa1 << ", bb1= " << bb1 << ", wcslen(bb1)=" << wcslen(bb1) << ", sizeof(bb1)=" << sizeof(bb1) << endl;
    // wcscpy_s(bb1, 16, aa1);  // ok 
    
    char aa2[1023] = "aaaaabbbbbccccc", bb2[1023] = { 0 };
    memcpy(bb2, aa2, 16 * sizeof(char));
    cout << "aa2= " << aa2 << ", bb2= " << bb2 << ", wcslen(bb2)=" << strlen(bb2) << ", sizeof(bb2)=" << sizeof(bb2) << endl;
    bb2[11] = '\0';
    cout << "aa2= " << aa2 << ", bb2= " << bb2 << ", wcslen(bb2)=" << strlen(bb2) << ", sizeof(bb2)=" << sizeof(bb2) << endl;

    wstring wa = L"aaaaabbbbb";
    cout << "len wa: " << wa.length() << endl;


    //===================================================
    
    cout << "################################################" << endl;
    wchar_t wszAC1[20] = L"aaaaabbbbbcccccdd", wszAC2[10] = {0};
    wcout << "wszAC2: " << wszAC2 << endl;
    wcsncpy_s(wszAC2, 9, wszAC1, _TRUNCATE);
    wcout << "wszAC2: " << wszAC2 << endl;
    

    // buffer is too small
    /*
    wchar_t wszAC1[20] = L"aaaaabbbbbcccccdd", wszAC2[10] = { 0 };
    wcout << "wszAC2: " << wszAC2 << endl;
    wcscpy_s(wszAC2, _countof(wszAC2), wszAC1);
    wcout << "wszAC2: " << wszAC2 << endl;
    */
    
    TCHAR szAC[20] = "aaaaabbbbbccccc";
    TCHAR szACTemp[10] = { 0 };
    cout << "szACTemp: " << szACTemp << endl;
    strncpy_s(szACTemp, _countof(szACTemp) - 1, szAC, _TRUNCATE);
    if (strlen(szACTemp) > 8)
    {
        szACTemp[8] = L'\0';
    }
    cout << "szACTemp: " << szACTemp << endl;


    wstring ws = L"aaaaabbbbbccccc";
    wstring ws2 = ws.substr(0,5);
    wcout << "ws2: " << ws2 << endl;


    std::string s{ 'a', 'b', '\0', 'c' };
    std::string s1 = "ab\0c";  // 这里由于是从 C-style string 构造 std::string，所以仍然会忽略 \0 之后的字符
    cout << s << endl;  // 输出 ab c
    cout << s1 << endl;  // 输出 ab

    system("pause");

    return 0;
}
