/*ref:
https://openhome.cc/Gossip/CppGossip/enumType.html
http://ascii-iicsa.blogspot.tw/2010/08/enum.html
http://en.cppreference.com/w/cpp/language/enum
*/

// http://karosesblog.blogspot.tw/2013/04/c-enum.html

#include <iostream>
using namespace std;

typedef enum { sun, mon, tue, wed, thu, fri, sat }week_type;
enum { on = 0, off = 1, no = 0, yes = 1 };
int main()
{
    week_type day;
    day = thu;

    cout << "Day" << day << endl;
    cout << on << " "<< off << " " << no <<" "<< yes;
    system("pause");
    return 0;
}