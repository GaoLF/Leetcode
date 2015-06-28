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
	void solve(vector<vector<char>>& board) {
        int row=board.size();
        if(!row)
        	return;
        int col=board[0].size();
        int i,j;
		for(i=0;i<row;i++){
			check(board,i,0,row,col);
			if(col>1)
				check(board,i,col-1,row,col);
		}
		for(j=1;j+1<col;j++){
			check(board,0,j,row,col);
			if(row>1)
				check(board,row-1,j,row,col);
		}
		for(i=0;i<row;i++)
			for(j=0;j<col;j++)
				if(board[i][j]=='O')
					board[i][j]='X';
		for(i=0;i<row;i++)
			for(j=0;j<col;j++)
				if(board[i][j]=='1')
					board[i][j]='O';
    }
	void check(vector<vector<char> >&vec,int i,int j,int row,int col){
		if(vec[i][j]=='O'){
			//cout<<"!!"<<i<<" "<<j<<endl;
			vec[i][j]='1';
			if(i>1)
				check(vec,i-1,j,row,col);
			if(j>1)
				check(vec,i,j-1,row,col);
			if(i+1<row)
				check(vec,i+1,j,row,col);
			if(j+1<col)
				check(vec,i,j+1,row,col);
		}
	}
    void print()
    {
		vector<vector<char> > A;
		vector<char> B;
		char C[]={'X','X','X','X'};
		char D[]={'X','O','X','X'};
		char E[]={'X','X','X','X'};
		char F[]={'X','O','X','X'};
		B=vector<char>(C,C+3);
		A.push_back(B);
		B=vector<char>(D,D+3);
		A.push_back(B);
		B=vector<char>(E,E+3);
		A.push_back(B);
		B=vector<char>(F,F+4);
		//A.push_back(B);
		solve(A);
		for(int i=0;i<A.size();i++){
			for(int j=0;j<A[0].size();j++)
				cout<<A[i][j]<<" ";
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
