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
    int minSubArrayLen(int s, vector<int>& nums) {
        int res=INT_MAX;
        int i,size=nums.size();
        int sum=0,begin=0;
        for(i=0;i<size;i++){
            sum+=nums[i];
            while(sum>=s&&i<size&&begin+1<size){
                res=min(res,i-begin+1);
                if(begin+1<size){
                	sum=nums[++begin];
                	i=begin;
				}   
            }
        }
        return res==INT_MAX?0:res;
    }

    void print()
    {
		int X[]={1,4,4,2,4,3};
		vector<int> A(X,X+6);
		vector<int> B(X,X+3);
		cout<<minSubArrayLen(7,A)<<endl;
		cout<<minSubArrayLen(4,B)<<endl;
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
