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
	int xx;
    void solveSudoku(vector<vector<char> > &board) {
        int i,j,m,sum,count;
        char cur;
        xx=0;
		while(1){
			for(i=0,count=0;i<9;i++){
				cout<<i<<":"<<endl;
				for(j=0;j<9;j++){
					if(board[i][j]=='.'){
						count+=1;
						int flag[9];
						int sum=0;
						for(m=0;m<9;m++)
							flag[m]=0;
						for(m=0;m<9;m++){
							cur=board[i][m];
							if(cur!='.')
								flag[cur-'1']=1;	
							cur=board[m][j];
							if(cur!='.')
								flag[cur-'1']=1;
							cur=board[i/3*3+m/3][j/3*3+m%3];
							if(cur!='.')
								flag[cur-'1']=1;				
						}
						for(m=0;m<9;m++)
							sum+=flag[m];
						cout<<sum;
						if(sum==8){
							for(m=0;m<9;m++)
								if(flag[m]==0)
									board[i][j]=m+'1';
							count--;
						}
						if(sum==7){
							for(m=0;m<9;m++)
								if(flag[m]==0){
									board[i][j]=m+'1';
									solveSudoku(board);
									if(xx)
										return;
									board[i][j]='.';
									
								}
							count--;
						}
					}
					if(i==8&&j==8&&count==0){
						xx=1;return;	
					}
										
				}
				cout<<endl;
			}
		} 
    }

    void print()
    {
		vector<vector<char> > A;
		vector<char> B;
		B.push_back('.');
		B.push_back('.');
		B.push_back('9');
		B.push_back('7');
		B.push_back('4');
		B.push_back('8');
		B.push_back('.');
		B.push_back('.');
		B.push_back('.');
		A.push_back(B);
		B.clear();	
		B.push_back('7');
		B.push_back('.');
		B.push_back('.');
		B.push_back('.');
		B.push_back('.');
		B.push_back('.');
		B.push_back('.');
		B.push_back('.');
		B.push_back('.');
		A.push_back(B);
		B.clear();	
		B.push_back('2');
		B.push_back('.');
		B.push_back('1');
		B.push_back('.');
		B.push_back('9');
		B.push_back('.');
		B.push_back('.');
		B.push_back('.');
		B.push_back('.');
		A.push_back(B);
		B.clear();	
		B.push_back('.');
		B.push_back('.');
		B.push_back('7');
		B.push_back('.');
		B.push_back('.');
		B.push_back('.');
		B.push_back('.');
		B.push_back('2');
		B.push_back('4');
		A.push_back(B);
		B.clear();	
		B.push_back('.');
		B.push_back('6');
		B.push_back('4');
		B.push_back('.');
		B.push_back('1');
		B.push_back('.');
		B.push_back('5');
		B.push_back('9');
		B.push_back('.');
		A.push_back(B);
		B.clear();	
		B.push_back('.');
		B.push_back('9');
		B.push_back('8');
		B.push_back('.');
		B.push_back('.');
		B.push_back('.');
		B.push_back('3');
		B.push_back('.');
		B.push_back('.');
		A.push_back(B);
		B.clear();	
		B.push_back('.');
		B.push_back('.');
		B.push_back('.');
		B.push_back('8');
		B.push_back('.');
		B.push_back('3');
		B.push_back('.');
		B.push_back('2');
		B.push_back('.');
		A.push_back(B);
		B.clear();	
		B.push_back('.');
		B.push_back('.');
		B.push_back('.');
		B.push_back('.');
		B.push_back('.');
		B.push_back('.');
		B.push_back('.');
		B.push_back('.');
		B.push_back('6');
		A.push_back(B);
		B.clear();	
		B.push_back('.');
		B.push_back('.');
		B.push_back('.');
		B.push_back('2');
		B.push_back('7');
		B.push_back('5');
		B.push_back('9');
		B.push_back('.');
		B.push_back('0');
		A.push_back(B);
		solveSudoku(A);
		for(int i=0;i<9;i++){
			for(int j=0;j<9;j++)
				cout<<A[i][j];
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
