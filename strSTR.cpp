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
    int strStr(char *haystack, char *needle) {
        int i,j,h_size,n_size,flag;
        for(i=0;haystack[i]!='\0';i++);
        h_size=i;
        for(i=0;needle[i]!='\0';i++);
        n_size=i;
        if(!n_size)
        	return 0;
        for(i=0;i<h_size;i++){
        	for(j=0;j<n_size&&needle[j]==haystack[j+i];j++);
        		if(j==n_size)
        			return i;
		}
		return -1;
    }

    void print()
    {
		char A[14]="AVVVVAVVVCAVC";
		char B[3]="VC";
		cout<<strStr(A,B)<<endl; 
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
