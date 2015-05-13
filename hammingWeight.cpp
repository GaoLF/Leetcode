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
    int hammingWeight(uint32_t n) {
        int res=0;
        for(int i=0;i<32;i++){
        	if(n&1)
        		res++;
        	n>>=1;
		}
		return res;
    }

    void print()
    {
		cout<<hammingWeight(11)<<endl; 
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
