#include<iostream>
#include<string>
#include<vector>
#include <cctype>
#include<algorithm>
using namespace std ;
class Solution {
public:
	bool isValidSudoku2(vector<vector<char> > &board) {
//		仅仅计算与三个条件符不符合，这样是不正确的！ 
		for(int row=0;row<9;row++)
		{
			for(int col=0;col<9;col++)
			{
				if(board[row][col]!='.')
				{
				    char cur=board[row][col];
					for(int j=0;j<9;j++)
					{
						if(board[j][col]==cur&&j!=row)
							return 0;//一行没有重复的 
						if(board[row][j]==cur&&j!=col)
							return 0;//一列没有重复的 
					}
					for(int j=0;j<3;j++)
					{//当前的3*3块没有重复的 
						if(board[j+row/3][col]==cur&&j+row/3!=row)
							return 0;
						if(board[row][j+col/3]==cur&&j+col/3!=col)
							return 0;
					}
				}
			}
		}
		return 1;
	}
	}
    bool isValidSudoku(vector<vector<char> > &board) {
        vector<vector<char> > curboard;
        curboard=board;
        int flag_suc=0;
        isvalidnum(curboard,0,0,board,flag_suc);
        return flag_suc;
    }
    bool isvalidnum(vector<vector <char> > &block,int row,int col,
					vector<vector <char> > &res,int &flag_suc)
    {
		char cur;
		int fullofzero=0;
		if(row==8&&col==9)
		{	
				//赋值 
				for(int i=0;i<9;i++)
					for(int j=0;j<9;j++)
						res[i][j]=block[i][j];
				flag_suc=1;
				return 1;
		}
		if(col==9&&row<8)
		{
			row++;
			col=0;
		}
		if(block[row][col]!='.')
		{
			isvalidnum(block,row,col+1,res,flag_suc);
			return 0;
		}
		for(int i=0;i<9;i++)
		{
			vector<vector<char> > curblock;
			curblock=block;
			int flag=1;
			cur='1'+i;
			for(int j=0;j<9;j++)
			{
				if(block[j][col]==cur)
					flag=0;//一行没有重复的 
				if(block[row][j]==cur)
					flag=0;//一列没有重复的 
			}
			for(int j=0;j<3;j++)
			{//当前的3*3块没有重复的 
				if(block[j+row/3][col]==cur)
					flag=0;
				if(block[row][j+col/3]==cur)
					flag=0;
			}
			if(flag)
			{
				curblock[row][col]=cur;
				isvalidnum(curblock,row,col+1,res,flag_suc);
			}
			
		}
		
		return 0;
	}
	void print()
	{
	vector<vector<char> > A;
	char p=' ';
	vector<char> cur;
	for(int i=0;i<9;i++)
		cur.push_back(p);
	for(int i=0;i<9;i++)
		A.push_back(cur);
	A[0][0]='.';A[0][1]='.';A[0][2]='5';A[0][3]='.';A[0][4]='.';A[0][5]='.';A[0][6]='.';A[0][7]='.';A[0][8]='6';
	A[1][0]='.';A[1][1]='.';A[1][2]='.';A[1][3]='.';A[1][4]='1';A[1][5]='4';A[1][6]='.';A[1][7]='.';A[1][8]='.';
	A[2][0]='.';A[2][1]='.';A[2][2]='.';A[2][3]='.';A[2][4]='.';A[2][5]='.';A[2][6]='.';A[2][7]='.';A[2][8]='.';
	A[3][0]='.';A[3][1]='.';A[3][2]='.';A[3][3]='.';A[3][4]='.';A[3][5]='9';A[3][6]='2';A[3][7]='.';A[3][8]='.';
	A[4][0]='5';A[4][1]='.';A[4][2]='.';A[4][3]='.';A[4][4]='.';A[4][5]='2';A[4][6]='.';A[4][7]='.';A[4][8]='.';
	A[5][0]='.';A[5][1]='.';A[5][2]='.';A[5][3]='.';A[5][4]='.';A[5][5]='.';A[5][6]='.';A[5][7]='3';A[5][8]='.';
	A[6][0]='.';A[6][1]='.';A[6][2]='.';A[6][3]='5';A[6][4]='4';A[6][5]='.';A[6][6]='.';A[6][7]='.';A[6][8]='.';
	A[7][0]='3';A[7][1]='.';A[7][2]='.';A[7][3]='.';A[7][4]='.';A[7][5]='.';A[7][6]='4';A[7][7]='2';A[7][8]='.';
	A[8][0]='.';A[8][1]='.';A[8][2]='.';A[8][3]='2';A[8][4]='7';A[8][5]='.';A[8][6]='6';A[8][7]='.';A[8][8]='.';
	cout<<isValidSudoku(A)<<endl;
	for(int i=0;i<9;i++)	
			{
				for(int j=0;j<9;j++)
					cout<<A[i][j]<<" ";
				cout<<endl;
			}
	cout<<endl;
	//for()
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
