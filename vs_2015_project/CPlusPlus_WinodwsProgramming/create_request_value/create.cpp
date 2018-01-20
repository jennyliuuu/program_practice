#include <fstream>      
#include <iostream>

using namespace std;

#define size 3000

void main()
{
	fstream file;
	char *str = new char[size];
	memset(str, 'a', size);
	file.open("Reader.txt", ios::out | ios::trunc);
	file.write(str, size);   
	file.close();      
	delete[] str;
}