#include<iostream>
#include<string>
#include<vector>
#include <cctype>
#include<algorithm>
using namespace std;
int set(int &x)
{
	x=4;
}
int main()
{
	int a=3;
	set(a);
	cout<<a<<endl;
	system("pause");
}
