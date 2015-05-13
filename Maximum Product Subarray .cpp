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
    int maxProduct(vector<int>& nums) {
		int size=nums.size();
		int i,foo,flag=0;
		int res=-1<<15;
		
		for(i=0;i<size;i++){
			if(!nums[i]){
				res=max(0,res);
				if(flag)
					res=max(res,check(nums,foo,i-1));
				flag=0;		
			}
			else{
				if(!flag)
					foo=i;
				flag=1;
			}
		}
		if(flag)
			res=max(res,check(nums,foo,i-1));
		return res;
    }
    int check(vector<int>& nums,int begin,int end){
    	int i,foo,bar,res;
		int a,b,c;
    	int first,last;
    	first=last=-1;
    	if(begin==end)
    		return nums[begin];
    	for(i=begin;i<=end;i++){
    		if(nums[i]<0){
    			if(first<0)
    				first=i;
    			last=i;
			}
		}
		if(first==-1){
			for(i=begin,a=1;i<=end;i++)
				a*=nums[i];
			return a;
		}
		
		foo=nums[first];
		bar=nums[last];
		for(i=begin,a=1;i<first;i++)
			a*=nums[i];
		for(i=first+1,b=1;i<last;i++)
			b*=nums[i];
		for(i=last+1,c=1;i<=end;i++)
			c*=nums[i];
		if(first==last)
			return max(a,c);
		res=a*b*c*foo*bar;
		res=max(res,a*foo*b);
		res=max(res,b*bar*c);
		return res;
	}

    void print()
    {
    	vector<int> A;
    	A.push_back(-2);
    	cout<<maxProduct(A)<<endl;
    	A.push_back(3);
    	cout<<maxProduct(A)<<endl;
		A.push_back(0);
    	cout<<maxProduct(A)<<endl;
		A.push_back(0);
    	cout<<maxProduct(A)<<endl;
    	A.push_back(-2);
    	cout<<maxProduct(A)<<endl;
		A.push_back(-2);
    	cout<<maxProduct(A)<<endl;
    	A.push_back(3);
    	cout<<maxProduct(A)<<endl;
    	A.push_back(-2);
    	cout<<maxProduct(A)<<endl;
    	A.push_back(4);
    	cout<<maxProduct(A)<<endl;
    	A.push_back(0);
    	cout<<maxProduct(A)<<endl;
    	A.push_back(5);
    	cout<<maxProduct(A)<<endl;

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
