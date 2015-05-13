#include<iostream>
#include<string>
#include<vector>
#include <cctype>
#include<algorithm>
#include<math.h>
using namespace std ;
typedef struct ListNode{
	int val;
	ListNode * next;
} ListNode;
class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        int i,j,res,step,shift;
        if(m==n)
            return m;
        res=m;
        for(i=m+1,shift=1,step=1;i<=n&&i>0;i+=step){
            res=res&i;
            if(!res)
            	return res;
			for(;(res%(1<<shift))==0;shift++);	
			step=(1<<(shift-1));   
			if(i+step>=n&&(step>1))
				step=step>>2;	
		}
        return res;
    }

    void print()
    {
    	cout<<((1<<31)-1)<<endl;
    	cout<< rangeBitwiseAnd(2147483646, 2147483647)<<endl;
		cout<< rangeBitwiseAnd(4, 8)<<endl;
		cout<< rangeBitwiseAnd(700000000, 2147483641)<<endl;
		cout<< rangeBitwiseAnd(5,7)<<endl;
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
