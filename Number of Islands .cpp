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
    int numIslands(vector<vector<char> > &grid) {
        int i,j,row,col,res;
		int **flag;
		
		row=grid.size();
		if(!row)
			return 0;
		col=grid[0].size();
		flag=(int **)malloc(sizeof(int*)*(row+2));
		for(i=0;i<(row+2);i++){
			flag[i]=(int *)malloc(sizeof(int)*(col+2));
			for(j=0;j<(col+2);j++)
				flag[i][j]=0;
		}
		for(i=0,res=0;i<row;i++){
			for(j=0;j<col;j++){
				if(grid[i][j]=='1'){
					if((!flag[i][j+1])&&(!flag[i+1][j]))
						flag[i+1][j+1]=++res;
					else{
						if(flag[i+1][j])
							flag[i+1][j+1]=flag[i+1][j];
						if(flag[i][j+1])
							flag[i+1][j+1]=flag[i][j+1];
						if((flag[i+1][j]&&flag[i][j+1])&&(flag[i+1][j]>flag[i][j+1]))
							res--;
					} 
				}
			}	
		}
		return res;
    }
    void print()
    {
    	vector<vector<char> > A;
    	vector<char> x;
    	x.push_back('1');
    	x.push_back('1');
    	x.push_back('1');
    	A.push_back(x);
    	
    	x.clear();
    	x.push_back('0');
    	x.push_back('1');
    	x.push_back('0');
    	A.push_back(x);
    	
    	x.clear();
    	x.push_back('1');
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
