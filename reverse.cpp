#include<iostream>
#include<string>
#include <sstream>
using namespace std;
class Solution {
public:

    int reverse(int x) {
        int res=0;
        int max=2147483647;
        int cur;
        while(x)
        {
            cur=x%10;
            x=x/10;
            res=res*10+cur;
            if(abs(x)>=1&&(abs(res)>(max/10)))
            	return 0;
        }
        return res;
    }
};
int main()
{
	Solution a;
	string b="";
	int c=2147483647;
	cout<<c<<endl;
	cout<<a.reverse(-2147480092)<<endl;
	system("pause");
} 
