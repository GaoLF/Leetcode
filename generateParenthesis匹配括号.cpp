#include<iostream>
#include<string>
#include<vector>
#include <cctype>
#include<algorithm>
#include<math.h>
using namespace std ;
struct ListNode{
	int val;
	ListNode *next;
	ListNode(int x):val(x),next(NULL){}
};
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        if(!n)
            return res;
        string cur="";
		for(int i=0;i<n;i++)
			cur+="(("; 
        transform(cur,0,0,n,res);
        return res;
            
    }
    int transform(string str,int begin,int have,int n,vector<string> &res)
    {
		int i,j;
		if(have==n)
		{
			res.push_back(str);
			return 0;
		}
		for(i=begin;i<2*n;i++)
		{
			string cur=str;
			if(2*have<i)
			{
				cur[i]=')';
				transform(cur,i+1,have+1,n,res);
			}
		}
	}
    void print()
    {
		vector<string> x;
		x=generateParenthesis(3);
		for(int i=0;i<x.size();i++)
				cout<<x[i]<<endl;
		cout<<endl;
		cout<<x.size()<<endl;
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
