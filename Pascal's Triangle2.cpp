#include<iostream>
#include<string>
#include<vector>
#include <cctype>
#include<algorithm>
using namespace std ;
class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> cur,cur1;
        int x,i,j;
		
        cur.push_back(1);
        if(!rowIndex)
			return cur;
        cur1.push_back(1);
        cur1.push_back(0);
        for(i=0;i<rowIndex;i++)
        {
			cur1.insert(cur1.begin(),0);
			for(j=0;j<cur.size();j++)
			{
				cur[j]=cur1[j]+cur1[j+1];
				cur1[j]=cur1[j]+cur1[j+1];
			}
			cur.push_back(cur1[j]+cur1[j+1]);
		}
		return cur;
	}
	void print(int x)
	{
		vector<int> res;
		res=getRow(x);
		for(int i=0;i<res.size();i++)
			cout<<res[i]<<endl;
	}
};
int main()
{
	Solution test;
//	cout<<test.Low("A man, a plan, a canal: Panama")<<endl;
	test.print(2);
//	cout<<atoi("2147483648")<<endl;
	system("pause");
}
