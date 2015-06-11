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
    int findKthLargest(vector<int>& nums, int k) {
        int size = nums.size();
        int res, temp;
        if(!size)
        	return 0;
        if(k > (size/2)){
        	k=size-k+1;
	        for(int i=0;i<k;i++){
				res = nums[0];
				auto foo = nums.begin();
				for(auto iter=nums.begin(); iter!=nums.end(); iter++){
	        		if(*iter < res){
	        			foo = iter;
	        			res = *iter;
					}
				}
				nums.erase(foo);
			}
		}
        else{
	        for(int i = 0; i < k; i++){
				res = nums[0];
				auto foo = nums.begin();
				for(auto iter = nums.begin(); iter != nums.end(); iter++){
	        		if(*iter > res){
	        			foo = iter;
	        			res = *iter;
					}
				}
				nums.erase(foo);
			}
		}
		return res;
    }

    void print()
    {
    	int X[]={3,2,1,4,6,5};
    	vector<int> A(X,X+6);
		//cout<<findKthLargest(A,0)<<endl;
		//cout<<findKthLargest(A,1)<<endl;
		cout<<findKthLargest(A,1)<<endl;
		//cout<<findKthLargest(A,3)<<endl;
		//cout<<findKthLargest(A,4)<<endl;
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
