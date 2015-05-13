#include<iostream>
#include<string>
#include<vector>
#include <cctype>
#include<algorithm>
using namespace std ;
class Solution {
public:
    vector<vector<string> > solveNQueens(int n) {
        vector<vector <string> > res;
        vector<int> cur;
		NQueens(0,0,n,cur,res);
        return res;
    }
    int NQueens(int i,int num,int n,vector<int> cur,vector<vector<string> > &res)//i:第i行，num：第i行的数 
    {
		if(i==n-1&&num==n)
			return 0;
		if(isGood(i,num,cur))//成功 
		{	
			if(i==n-1)
			{
				cur.push_back(num);
				vector<string> Q;
				for(int row=0;row<n;row++)
				{
					string P="";
					for(int col=0;col<n;col++)
					{
						if(col==n-cur[row]-1)
							P+="Q";
						else
						 	P+=".";
					}
					Q.push_back(P);
				}
				res.push_back(Q);
				return 0;
			}
			vector<int> A=cur;
			cur.push_back(num);	
			NQueens(i+1,0,n,cur,res);
			if(num<n-1)
			NQueens(i,num+1,n,A,res);
		}
		else if(!isGood(i,num,cur)) //不是最后一行，不成功
		{
			if(num==n-1)
				return 0;
			NQueens(i,num+1,n,cur,res);
		} 
	}
	bool isGood(int i,int num,vector<int> cur)
	{
		for(int j=0;j<i;j++)
			if(abs(cur[j]-num)==i-j||cur[j]==num)
				return 0;
		return 1;
	}
    void print()
    {
		vector<vector<string> > res;
		int n=4;
		res=solveNQueens(n);
		for(int i=0;i<res.size();i++)
		{
			for(int j=0;j<n;j++)
				cout<<res[i][j]<<endl;		
			cout<<endl;
		}
//		cout<<endl;
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
