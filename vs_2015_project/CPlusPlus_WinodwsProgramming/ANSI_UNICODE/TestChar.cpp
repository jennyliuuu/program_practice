//#include <iostream>
//using namespace std;
//
//int main()
//{
//    char ch1 = 's';             // 正确
//    cout << "ch1:" << ch1 << endl;
//    char ch2 = '中';             // 错误,一个 char 不能完整存放一个汉字信息
//    cout << "ch2:" << ch2 << endl;
//
//    char str[5] = "中";          //前三个字节存放汉字'中',最后一个字节存放字符串结束符\0
//    cout << "str:" << str << endl;
//    char str2[2] = "国";       // 错误：'str2' : array bounds overflow
//    cout << str2 << endl;
//    system("pause");
//    return 0; 
//}