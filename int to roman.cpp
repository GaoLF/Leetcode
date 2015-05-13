#include<iostream>
#include<string>
#include<vector>
#include <cctype>
#include<algorithm>
using namespace std ;
class Solution {
public:
    string intToRoman(int num) {
        int thousand,hundred,ten,one;
        thousand=num/1000;
        hundred=(num/100)%10;
        ten=(num/10)%10;
    	one=num%10;
    	string res="";
    	int i;
		for(i=0;i<thousand;i++)
			res+="M";
		if(hundred==9)
			res+="CM";
		else if(hundred==4)
			res+="CD";
		else
		{ 
			if(hundred>=5)
			{
				res+="D";
				hundred-=5;
			}
			for(i=0;i<hundred;i++)
				res+="C";
		}
		if(ten==9)
			res+="XC";
		else if(ten==4)
			res+="XL";
		else 
		{	
			if(ten>=5)
			{
				res+="L";
				ten-=5;
			}
			for(i=0;i<ten;i++)
				res+="X";
		}
		if(one==9)
			res+="IX";
		else if(one==4)
			res+="IV";
		else
		{ 
			if(one>=5)
			{
				res+="V";
				one-=5;
			}
			for(i=0;i<one;i++)
				res+="I";
		}
		return res;
				
//    	cout<<thousand<<"\t"<<hundred<<"\t"<<ten<<"\t"<<one<<endl;
 //   	return "aa";
    }
    void print()
    {
		cout<<intToRoman(1984)<<endl;
		cout<<intToRoman(1666)<<endl;
	}
};
int main()
{
	Solution test;
	int a[4]={0};
	for(int i=0;i<4;i++)
		cout<<a[i]<<endl; 
	
//	cout<<test.Low("A man, a plan, a canal: Panama")<<endl;
//	test.print();
//	cout<<atoi("2147483648")<<endl;
	system("pause");
}
