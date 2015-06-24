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
    int numIslands(vector<vector<char> >& grid) {
        int row=grid.size();
        if(!row)
        	return 0;
        int col=grid[0].size();
        vector<int> temp(col,0);
        vector<vector<int> > flag(row,temp);
        int i,j,res=0;
        
		for(i=0;i<row;i++){
			for(j=0;j<col;j++){
				if(grid[i][j]=='1'&&flag[i][j]==0){
					write_flag(flag,grid,i,j);
					res++;
				}
			}
		}
		return res;
    }
	void write_flag(vector<vector<int> > &flag,vector<vector<char> >&grid,int i,int j){
		flag[i][j]=1;
		//cout<<i<<" "<<j<<endl;
		if(i>0&&grid[i-1][j]=='1'&&flag[i-1][j]==0)
			write_flag(flag,grid,i-1,j);
		if(i+1<grid.size()&&grid[i+1][j]=='1'&&flag[i+1][j]==0)
			write_flag(flag,grid,i+1,j);
		if(j>0&&grid[i][j-1]=='1'&&flag[i][j-1]==0)
			write_flag(flag,grid,i,j-1);
		if(j+1<grid[0].size()&&grid[i][j+1]=='1'&&flag[i][j+1]==0)
			write_flag(flag,grid,i,j+1);
	}
    void print()
    {
		vector<vector<char> > A;
    	vector<char> x;
    	x.push_back('1');
    	x.push_back('1');
    	x.push_back('0');
    	x.push_back('0');
    	x.push_back('0');
    	A.push_back(x);
    	
    	x.clear();
    	x.push_back('1');
    	x.push_back('1');
    	x.push_back('0');
    	x.push_back('0');
    	x.push_back('0');
    	A.push_back(x);
    	
    	x.clear();
    	x.push_back('0');
    	x.push_back('0');
    	x.push_back('1');
    	x.push_back('0');
    	x.push_back('0');
    	A.push_back(x);

    	x.clear();
    	x.push_back('0');
    	x.push_back('0');
    	x.push_back('0');
    	x.push_back('1');
    	x.push_back('1');
    	A.push_back(x);
    	

    	cout<<numIslands(A)<<endl;
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
