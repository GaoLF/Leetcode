#include<iostream>
#include<string>
#include<vector>
#include <cctype>
#include<algorithm>
using namespace std ;
class Solution {
public:
    vector<vector<int> > generate(int numRows) {
        vector<int> cur,cur1;
        int x,i,j;
        vector<vector <int> > res;
		if(!numRows)
			return res;
        cur.push_back(1);
        res.push_back(cur);
        cur1.push_back(1);
        cur1.push_back(0);
        for(i=0;i<numRows-1;i++)
        {
			cur1.insert(cur1.begin(),0);
			for(j=0;j<cur.size();j++)
			{
				cur[j]=cur1[j]+cur1[j+1];
				cur1[j]=cur1[j]+cur1[j+1];
			}
			cur.push_back(cur1[j]+cur1[j+1]);
			res.push_back(cur);
		}
		return res;
	}
	void print(int x)
	{
		vector<vector<int> > res;
		res=generate(x);
		for(int i=0;i<res[x-1].size();i++)
			cout<<res[x-1][i]<<endl;
	}
};
int main()
{
	Solution test;
//	cout<<test.Low("A man, a plan, a canal: Panama")<<endl;
	test.print(6);
//	cout<<atoi("2147483648")<<endl;
	system("pause");
}
