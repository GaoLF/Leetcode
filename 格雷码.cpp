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
    vector<int> grayCode(int n) {
        vector<int> res;
    	res.push_back(0);
    	if(n>=1)
    	    res.push_back(1);
        for(int i=1;i<n;i++)
        {
            int cur;
            int size=res.size();
            for(int j=0;j<size;j++)
            {
                cur=pow(2,i)+res[size-j-1];
                res.push_back(cur);
            }
        }
		return res;
    }
    void print()
    {
		vector<int> x;
		x=grayCode(10);
		for(int i=0;i<x.size();i++)
				cout<<x[i]<<"  ";
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
