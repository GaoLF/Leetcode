#include<iostream>
#include<string>
#include<vector>
#include <cctype>
#include<algorithm>
using namespace std ;
class Solution {
public:
    bool canJump(int A[], int n) {
		int i,j,flag;
    	for(i=0;i<n-1;i++)
		{
			if(!A[i])
			{
				j=i;
				for(flag=0;!A[i]&&i!=n-1;i++,flag++);
				cout<<"i: "<<i<<" j:"<<j<<" flag: "<<flag<<endl;
				for(;j&&j+A[j]<i;j--);
				if(j==0&&j+A[j]<i)
					return 0;
			}
		}    
		return 1;
    }
    void print()
    {
		int A[10]={-1};
		A[0]=2;
		A[1]=0;
		A[2]=0;
		A[3]=0;
		A[4]=4;
		A[5]=2;
		cout<<canJump(A,3)<<endl;
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
