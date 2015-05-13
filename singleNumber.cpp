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
    int singleNumber(int A[], int n) {
        int fuzhu=0;
        int a=0,b=0; 
        for(int i=0;i<n;i++){
            fuzhu=b&A[i];
            b=b^A[i];
            a=a|fuzhu;
            fuzhu=b&a;
            b=b^fuzhu;
            a=a^fuzhu;
        } 
   //     cout<<sum<<endl<<res<<endl<<endl;
        return b;
    }
    void print()
    {
        int A[10]={1,1,1,2,2,2,3,3,3,4};
        cout<<singleNumber(A,0)<<endl;
	}
};
int main()
{
	Solution test;
//    cout<<a<<endl;
//	cout<<test.Low("A man, a plan, a canal: Panama")<<endl;
	test.print();
//	cout<<atoi("2147483648")<<endl;
	system("pause");
}
