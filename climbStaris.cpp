#include<iostream>
#include<string>
#include<vector>
#include <cctype>
#include<algorithm>
using namespace std ;
class Solution {
public://斐波那契数列的感觉，不要用递归写，时间复杂度太高好像，而且下边的递归写的不正确。 
    int climbStairs(int n) {
		int res=1;
		int cur=1;
		for(int i=1;i<n;i++)
		{
		    res+=cur;
		    cur=res-cur;
		}
		return res;	
	}
	/*
	int climbStairs(int n) {
        int methods=0;
        compute(n-1,methods);
        compute(n-2,methods);
        return methods;
    }
    int compute(int n,int &num)
    {
        if(!n)
            return 0;
        if(n>=1)
        {
			num++;
            compute(n-1,num);
        }
        if(n>=2)
        {
            num++;
            compute(n-2,num);
        }

    }
    */
    void print()
	{
		cout<<climbStairs(5)<<endl;
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
