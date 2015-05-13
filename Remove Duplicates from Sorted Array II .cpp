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
    int removeDuplicates(int A[], int n) {
        int flag=0;
		int i,j,length=0;
		for(i=0,j=0;j<n;i++){
			for(flag=0;j<n-1;j++){
				if(A[j]==A[j+1]){
					flag=1;
				}
				else
					break;
			}
			cout<<"i: "<<i<<" j: "<<j<<endl;
			A[i]=A[j++];
			length++;
			if(flag){
				A[++i]=A[j-1];
				length++;
			}
		} 
		return length;
    }
    void print(){
    	int size=9;
		int A[10]={1,1,1,2,3,3,3,3,4};
		int res=removeDuplicates(A,0);
		cout<<res<<endl;
		for(int i=0;i<size-1;i++)
			cout<<A[i]<<"->";
		cout<<A[size-1]<<endl;
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
