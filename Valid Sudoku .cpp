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
	
    bool isValidSudoku(vector<vector<char> > &board) {
        vector<char> ver,hor,square;
		vector<vector<char> > bar;
		int i,j;
		char foo;
		for(i=0;i<9;i++){
			hor.clear();
			ver.clear();
			square.clear();
			for(j=0;j<9;j++){
					hor.push_back(board[i][j]);
					ver.push_back(board[j][i]);
					square.push_back(board[i/3*3+j/3][(i%3)*3+j%3]);
			}
			bar.push_back(hor);
			bar.push_back(ver);				
			bar.push_back(square);
		}
		for(i=0;i<bar.size();i++){
			if(check(bar[i]))
				return 0;
		}
		return 1;
    }
    int check(vector<char> &X){
    	int i,j;
		for(i=1;i<9;i++){
			for(j=0;j<i;j++){
				if((X[i]!='.')&&(X[i]==X[j]))
					return 1;
			}
		}
		return 0;
	}

    void print()
    {
		vector<vector<char> > A;
		vector<char> B;
		B.push_back('5');
		B.push_back('3');
		B.push_back('.');
		B.push_back('.');
		B.push_back('7');
		B.push_back('.');
		B.push_back('.');
		B.push_back('.');
		B.push_back('.');
		A.push_back(B);
		B.clear();	
		B.push_back('6');
		B.push_back('.');
		B.push_back('.');
		B.push_back('1');
		B.push_back('9');
		B.push_back('5');
		B.push_back('.');
		B.push_back('.');
		B.push_back('.');
		A.push_back(B);
		B.clear();	
		B.push_back('.');
		B.push_back('9');
		B.push_back('8');
		B.push_back('.');
		B.push_back('.');
		B.push_back('.');
		B.push_back('.');
		B.push_back('6');
		B.push_back('.');
		A.push_back(B);
		B.clear();	
		B.push_back('8');
		B.push_back('.');
		B.push_back('.');
		B.push_back('.');
		B.push_back('6');
		B.push_back('.');
		B.push_back('.');
		B.push_back('.');
		B.push_back('3');
		A.push_back(B);
		B.clear();	
		B.push_back('4');
		B.push_back('.');
		B.push_back('.');
		B.push_back('8');
		B.push_back('.');
		B.push_back('3');
		B.push_back('.');
		B.push_back('.');
		B.push_back('1');
		A.push_back(B);
		B.clear();	
		B.push_back('7');
		B.push_back('.');
		B.push_back('.');
		B.push_back('.');
		B.push_back('2');
		B.push_back('.');
		B.push_back('.');
		B.push_back('.');
		B.push_back('6');
		A.push_back(B);
		B.clear();	
		B.push_back('.');
		B.push_back('6');
		B.push_back('.');
		B.push_back('.');
		B.push_back('.');
		B.push_back('.');
		B.push_back('2');
		B.push_back('8');
		B.push_back('.');
		A.push_back(B);
		B.clear();	
		B.push_back('.');
		B.push_back('.');
		B.push_back('.');
		B.push_back('4');
		B.push_back('1');
		B.push_back('9');
		B.push_back('.');
		B.push_back('.');
		B.push_back('5');
		A.push_back(B);
		B.clear();	
		B.push_back('.');
		B.push_back('.');
		B.push_back('.');
		B.push_back('.');
		B.push_back('8');
		B.push_back('.');
		B.push_back('.');
		B.push_back('7');
		B.push_back('9');
		A.push_back(B);
		cout<<isValidSudoku(A)<<endl;
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
