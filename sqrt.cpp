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
    int mySqrt(int x) {
        int i,start,end,size;
		for(size=0;size<32;size++){
			if((x>>size)==0)
				break;
		}
		start=max(0,1<<(size/2)-1);
		end=1<<(size/2)+1;
		for(i=start;i<=end;i++){
			if(i*i==x)
				return i;
			if(i*i>x||i*i<0)
				return i-1;
		}
	//	return i;
    }

    void print()
    {
		for(int i=0;i<100;i++){
			cout<<mySqrt(i)<<endl;
		}
		cout<<mySqrt(2147483647)<<endl;
		
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
