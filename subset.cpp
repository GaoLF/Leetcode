#include<iostream>
#include<string>
#include<vector>
#include <cctype>
#include<algorithm>
using namespace std ;
struct ListNode{
	int val;
	ListNode *next;
	ListNode(int x):val(x),next(NULL){}
};
class Solution {
public:
    vector<vector<int> > subsets(vector<int> &S) {
        vector<int> cur;
        vector<vector <int> > res;
        res.push_back(cur);
        for(int i=0;i!=S.size();i++)
        {
			int size=res.size();
            for(int j=0;j!=size;j++)
            {
                cur=res[j];
                cur.push_back(S[i]);
                res.push_back(cur);
            }
        }
        for(int i=0;i<res.size();i++)
        	sort(res[i].begin(),res[i].end());
        return res;
    }
    void print()
    {
		vector<int> X;
		X.push_back(4);
		X.push_back(2);
		X.push_back(0);
		vector<vector <int> > res;
		res=subsets(X);
		for(int i=0;i<res.size();i++)
		{
			for(int j=0;j<res[i].size();j++)
			{
				cout<<res[i][j];
			}
			cout<<endl;
		} 
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
