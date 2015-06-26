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
    vector<string> summaryRanges(vector<int>& nums) {
        int i,size=nums.size();
        vector<string> res;
        string temp;
        char foo[32];
        int begin;
        
        if(!size)
        	return res;
        begin=nums[0];
        sprintf(foo,"%d",begin);
		temp=foo;
        for(i=1;i<=size;i++){
        	if(i<size&&nums[i]-nums[i-1]==1);
        	else if(nums[i-1]==begin){
				res.push_back(temp); 
        		begin=nums[i];
        		sprintf(foo,"%d",begin);
				temp=foo;
			}
			else if(nums[i-1]>begin){
				temp+="->";
				sprintf(foo,"%d",nums[i-1]);
				temp+=foo;
				res.push_back(temp);
				begin=nums[i];
				sprintf(foo,"%d",begin);
				temp=foo;
			}
		}
		
		return res;
    }

    void print()
    {
		int A[] ={-1,0,1,2,4,5,7};
		vector<int> B(A,A+7);
		vector<string> res=summaryRanges(B);
		int i;
		for(i=0;i<res.size();i++)
			cout<<res[i]<<" ";
		cout<<endl;
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
