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
	uint32_t reverseBits(uint32_t n) {
        uint32_t size=0;
        uint32_t res=0;
        while(!n){
            size=(uint32_t)(log((int)n)/log(2));
            n=n-1<<size;
            res+=1<<(32-size);
        }
        return  res;
    }
    void print()
    {
        cout<<reverseBits(43261596)<<endl;
	}
};
int main()
{
//	Solution test;
//	cout<<test.Low("A man, a plan, a canal: Panama")<<endl;
//	test.print();
//	cout<<atoi("2147483648")<<endl;
	system("pause");
}
