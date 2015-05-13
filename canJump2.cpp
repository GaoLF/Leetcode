#include<iostream>
#include<string>
#include<vector>
#include <cctype>
#include<algorithm>
using namespace std ;
class Solution {
public:
    int jump(int A[], int n) {
		if(!n||n==1)
			return 0;
		int B[n];
		int i,j,flag=0;
		for(i=0;i<n;i++)
			B[i]=0;
		if(A[0])
			B[0]=1;
		else
			return 0;
		for(i=0;i<n-1;i++)
		{
			if(B[i]==0)
				return 0;
			if(A[i]+i>=n-1)
				return B[i];
			if(A[i]+i>flag)		
			{	
				int x=A[i]+i-flag;	
				for(j=0;j<x;j++)
					B[++flag]=B[i]+1;
			}
//			for(int p=0;p<n;p++)
//				cout<<"n: "<<p<<"  "<<B[p]<<endl;
//			cout<<endl;
		}
		return B[n-1]-1;	
    }
    void print()
    {
		int A[10]={-1};
		A[0]=7;
		A[1]=6;
		A[2]=5;
		A[3]=4;
		A[4]=3;
		A[5]=2;
		A[6]=1;
		A[7]=0;
		A[8]=1;
		
		cout<<jump(A,9)<<endl;
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
