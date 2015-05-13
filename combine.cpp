#include<iostream>
#include<string>
#include<vector>
#include <cctype>
#include<algorithm>
#include<math.h>
using namespace std ;
class Solution {
public:
    vector<vector<int> > combine(int n, int k) {
        vector<vector<int> > res;
        vector<int> cur;
        trans(k,n,cur,res);
        for(int i=0;i<res.size();i++)
            sort(res[i].begin(),res[i].end());
        return res;
    }
    int trans(int n,int k,vector<int> cur,vector<vector<int> >&res)
    {
		//思路就是：比如说输入n=5,k=3
        //首先判断n==k，等于一股脑加入cur，再判断n==1，等于分别每一个加进去，这两种情况意味结束，将cur push入res
        //如果不等于以上两个条件，则分两种情况：trans(4,3)意思为不包含5在1-4中找3个；
        //将5加入cur，trans(5,2)，意思为包含5，然后在1-4里找两个
        int i,j;
        if(n==k)
        {
            for(i=0;i<n;i++)
                cur.push_back(i+1);
            res.push_back(cur);
            return 0;
        }
        if(n==1)
        {
			vector<int> x;
            for(i=0;i<k;i++)
            {	
                x=cur;
                x.push_back(i+1);
                res.push_back(x);
            }
            return 0;
        }
        trans(n,k-1,cur,res);
        cur.push_back(k);
        trans(n-1,k-1,cur,res);
    }
    void print()
    {
		vector<vector <int> > x;
		vector<int> y;
		y.push_back(1);
		y.push_back(2);
		y.push_back(3);
		y.push_back(4);
		//x.push_back(y);
		x=combine(4,2);
		cout<<endl<<endl;
		for(int i=0;i<x.size();i++)
		{
			for(int j=0;j<x[0].size();j++)
				cout<<x[i][j]<<" ";
			cout<<endl;
		}
		cout<<endl;
		//cout<<x.size()<<endl;
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
