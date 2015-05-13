#include<iostream>
#include<string>
#include <sstream>
#include<math.h>
using namespace std;
class Solution {
public:
    bool isPalindrome(int x) {
		int m,cur=x;
		if(x>2147483647||x<-2147483647||x<0)
			return 0;
		for(m=0;cur;cur=cur/10,m++);
    	return isP(x,m);
	}
	bool isP(int x,int m){ 
		if(x<10&&(m==1||m==0))
			return 1;
        if(x%10==x/(int)pow(10,m-1))
    	{
			x=x%(int)pow(10,m-1);
			x=x/10;
			cout<<x<<endl;
			return isP(x,m-2);
		}
		else
			return 0;
    }
};
int main()
{
	Solution a;
	string b="";
	int c=2147483647;
//	cout<<c<<endl;
//cout<<-2147447412<<endl;
	cout<<a.isPalindrome(0)<<endl;
	system("pause");
} 
