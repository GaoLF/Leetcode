#include<iostream>
#include<string>
#include<vector>
#include <cctype>
#include<algorithm>
using namespace std ;
class Solution {
public:
//一遍循环，就是设置一个fisrt位表示first以前全为0，last位以后都为2
//遍历过程，如果0，first++,如果1，不作为，如果2，交换位置，last设置2，last--
    void sortColors(int A[], int n) {
		int first,last,i,j;
		i=first=0;
		last=n-1;
		while(i-1!=last)
		{
			if(!A[i])//<0
			{
				A[i]=1;
				i++;
				A[first++]=0; 
			} 
			else if(A[i]==1)
				i++;
			else if(A[i]==2)
			{
				A[i]=A[last];
				A[last--]=2;
			}		
		}
    }
    void print()
    {
		//int A[0]={};
		int A[10]={1,0,1,2,2,1,0,1,0};
		sortColors(A,1);
		for(int i=0;i<9;i++)
			cout<<A[i];
		
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
