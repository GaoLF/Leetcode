#include<iostream>
#include<string>
#include<vector>
#include <cctype>
#include<algorithm>
using namespace std ;
class Solution {
public:
    int totalNQueens(int n) {
        vector<int> cur;
        int res=0;
		NQueens(0,0,n,cur,res);
        return res;
    }
    int NQueens(int i,int num,int n,vector<int> cur,int &res)//i:第i行，num：第i行的数 
    {
		if(i==n-1&&num==n)
			return 0;
		if(isGood(i,num,cur))//成功 
		{	
			if(i==n-1)
			{
				res++;
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
		int res;
		int n=4;
		res=totalNQueens(n);
		cout<<res<<endl;
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
