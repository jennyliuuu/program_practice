#include <iostream>
#include <locale>
using namespace std;

int main()
{
    //wcout.imbue(locale("chs"));     // 将 wcout 的本地化语言设置为中文
    setlocale(LC_CTYPE, "chs");

    wchar_t wch1 = L's';            // 正确
    wcout << "wch1:" << wch1 << endl;
    wchar_t wch2 = L'中';            // 正确,一个汉字用一个 wchar_t 表示
    wcout << "wch2:" << wch2 << endl;

    wchar_t wstr[2] = L"中";         // 前两个字节(前一个 wchar_t)存放汉字'中',最后两个字节(后一个 wchar_t)存放字符串结束符\0
    wcout << "wstr:" << wstr << endl;
    wchar_t wstr2[3] = L"中国";
    wcout << "wstr2:" << wstr2 << endl;

    system("pause"); 
    return 0;
}