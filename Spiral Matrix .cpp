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
    vector<int> spiralOrder(vector<vector<int> > &matrix) {
        vector<int> res;
		int col,row=matrix.size(),cur;
		int flag,i,j;
		if(!row)
			return res;
		col=matrix[0].size();
		enum dir{
			right=0,down,left,up
		};
		i=0;
		j=0;
		flag=right;
		for(int pp=0;pp<(row*col);pp++){
			res.push_back(matrix[i][j]);
			if(flag==right){			
				if(j<(col-i-1)){
					j++;
				}
				else{
					i++;
					flag=(flag+1)%4;
				}
			}
			else if(flag==down){
				if(i<(row-(col-j))){
					i++;
				}
				else{
					j--;
					flag=(flag+1)%4;
				}
			}
			else if(flag==left){
				if(j>(row-i-1)){
					j--;
				}
				else{
					i--;
					flag=(flag+1)%4;
				}
			}
			else if(flag==up){
				if(i>(j+1)){
					i--;
				}
				else{
					j++;
					flag=(flag+1)%4;
				}

			}

		}
		
		return res;
    }

    void print()
    {
    	vector<vector<int> > A;
    	vector<int> B;
    	B.push_back(1);
    	B.push_back(2);
    	B.push_back(3);
    	A.push_back(B);
    	spiralOrder(A); 
    	B.clear();
    	B.push_back(4);
    	B.push_back(5);
    	B.push_back(6);
    	A.push_back(B);
    	B.clear();
    	spiralOrder(A); 
    	B.push_back(7);
    	B.push_back(8);
    	B.push_back(9);
    	A.push_back(B);
    	cout<<A[1][2]<<endl;
    	
    	spiralOrder(A); 

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
