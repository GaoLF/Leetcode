#include<iostream>
#include<string>
#include<vector>
#include <cctype>
#include<algorithm>
#include<math.h>
#include<limits.h>
using namespace std ;
typedef struct ListNode{
	int val;
	ListNode * next;
} ListNode;
class Solution {
public:
    int divide(int dividend, int divisor) {
    	int i,flag,res=0,foo,sum,sign=0,bar=0;
    	
        if(!divisor)
        	return INT_MAX;
        if(!dividend)
        	return 0;
        if(divisor==1)
        	return dividend;
        if((dividend<0&&divisor>0)||(dividend>0&&divisor<0))
        	sign=-1;
        if(dividend==INT_MIN){
        	dividend+=1;
        	bar=1;
		}
        if(divisor==INT_MIN)
        	divisor+=1;
		dividend=abs(dividend);
		divisor=abs(divisor);
		//cout<<dividend<<" "<<divisor<<endl;
		//cout<<dividend<<" "<<divisor<<endl;
        for(flag=1,foo=divisor;foo>=divisor;){
        	if(dividend>=foo){
        		res+=flag;
        		if(res<0)
        			return INT_MAX;
        		dividend-=foo;
        		if(bar){
        			//cout<<dividend<<" "<<res<<" "<<flag<<" "<<divisor<<endl;
        			dividend++;
        			//res++;
        		//	cout<<dividend<<" "<<res<<" "<<flag<<" "<<divisor<<endl;
        			bar=0;
				}
        		if((foo<<1)>0&&(foo<<1)<dividend){
					foo<<=1;
        			flag<<=1;
        		}
        		if(bar){
        			
        			//cout<<dividend<<endl;
        			dividend+=1;
        			//cout<<dividend<<endl;
        			bar=0;
				}
        		//sum+=foo;
			}
			else{
				flag>>=1;
			//	cout<<foo<<"!!";
				foo>>=1;
			//	cout<<foo<<endl;
			}
			cout<<dividend<<" "<<res<<" "<<flag<<" "<<divisor<<" "<<foo<<endl;
		}
		if(sign)
			return -1*res;
		else
			return res;
    }

    void print()
    {
		cout<<divide(4,-3)<<endl;
		cout<<divide(2147483646,2)<<endl;
		cout<<divide(-1010369383, -2147483648)<<endl;
		//cout<<INT_MAX<<" "<<INT_MIN<<endl;
		cout<<divide(2147483648, -1)<<endl;
	}
};
int main()
{
	Solution test;

//	cout<<test.Low("A man, a plan, a canal: Panama")<<endl;
	test.print();
//	cout<<atoi("2147483648")<<endl;
	system("pause");
}
