#include<iostream>
#include<string>
#include<vector>
#include <cctype>
#include<algorithm>
#include<unordered_set> 
#include<math.h>
using namespace std ;
typedef struct ListNode{
	int val;
	ListNode * next;
} ListNode;
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int > set;
        for(int i=0;i<nums.size();i++)
        	set.insert(nums[i]);
        if(nums.size()==set.size())
        	return 1;
        else
        	return 0;
    }
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_set<int> set;
        int i;
        int size=nums.size();
		//if(k<size)
			k++;
        if(k>size)
        	k=size;
        
        for(i=0;i<k-1;i++)
        	set.insert(nums[i]);
        for(i=k-1;i<size;i++){
        	//temp=nums[i-k];
        	set.insert(nums[i]);
        	//cout<<k<<" "<<set.size()<<" "<<i-k<<endl;
        	if(set.size()!=k)
        		return 1;
        	set.erase(nums[i-k+1]);
        	
		}
		return 0;
    }
    void print()
    {
    	int X[6]={5,1,3,7,4,5};
		vector<int> A(X,X+6);
		cout<<containsNearbyDuplicate(A,1)<<endl;
		cout<<containsNearbyDuplicate(A,2)<<endl;
		cout<<containsNearbyDuplicate(A,3)<<endl;
		cout<<containsNearbyDuplicate(A,4)<<endl;
		cout<<containsNearbyDuplicate(A,5)<<endl;
		cout<<containsNearbyDuplicate(A,6)<<endl;
		cout<<containsNearbyDuplicate(A,7)<<endl;
		cout<<containsNearbyDuplicate(A,8)<<endl;
		cout<<containsNearbyDuplicate(A,9)<<endl;
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
