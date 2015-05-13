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
    bool exist(vector<vector<char> > &board, string word) {
        int row = board.size();
		if(!row)
			return 0;
		int col = board[0].size();
		int i,j;
		
		int **flag=(int **)malloc(sizeof(int*)*row);
		if(!word.length())	
			return 1;
		for(i=0;i<row;i++){
			flag[i]=(int*)malloc(sizeof(int)*col);
			for(j=0;j<col;j++)
				flag[i][j]=0;
		}
		for(i=0;i<row;i++){
			for(j=0;j<col;j++){
				if(board[i][j]==word[0]){
					flag[i][j]=1;
					if(check(board,word,i,j,row,col,1,flag))
						return 1;
					flag[i][j]=0;
				}
			}
		}
		return 0;
    }
    bool check(vector<vector<char> > &board, string word, int i, int j,
			   int row, int col, int str_iter,int **flag){
    	
		if(str_iter==word.length())
    		return 1;
		if(i>0){
			if((board[i-1][j]==word[str_iter])&&(flag[i-1][j]==0)){
				flag[i-1][j]=1;
				cout<<word[str_iter]<<" ";
				if(check(board,word,i-1,j,row,col,str_iter+1,flag))
					return 1;
				flag[i-1][j]=0;
			}
		}
		if(j>0){
			if((board[i][j-1]==word[str_iter])&&(flag[i][j-1]==0)){
				flag[i][j-1]=1;
				cout<<word[str_iter]<<" ";
				if(check(board,word,i,j-1,row,col,str_iter+1,flag))
					return 1;
				flag[i][j-1]=0;
			}
		}
		if(i<row-1){
			if((board[i+1][j]==word[str_iter])&&(flag[i+1][j]==0)){
				flag[i+1][j]=1;
				cout<<word[str_iter]<<" ";
				if(check(board,word,i+1,j,row,col,str_iter+1,flag))
					return 1;
				flag[i+1][j]=0;
			}
		}
		if(j<col-1){
			if((board[i][j+1]==word[str_iter])&&(flag[i][j+1]==0)){
				flag[i][j+1]=1;
				cout<<word[str_iter]<<" ";
				if(check(board,word,i,j+1,row,col,str_iter+1,flag))
					return 1;
				flag[i][j+1]=0;
			}
		}
		return 0;
	}
    

    void print()
    {
		vector<vector<char> > A;
		vector<char> B;
		
		A.push_back(B);
		A.push_back(B);
		A.push_back(B);
		 
		A[0].push_back('A');
		A[0].push_back('B');
		A[0].push_back('C');
		A[0].push_back('E');
		
		A[1].push_back('S');
		A[1].push_back('F');
		A[1].push_back('C');
		A[1].push_back('S');
		
		A[2].push_back('A');
		A[2].push_back('D');
		A[2].push_back('E');
		A[2].push_back('E');
	
		cout<<exist(A,"ABCCED");
		cout<<exist(A,"SEE");
		cout<<exist(A,"ABCB");
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
