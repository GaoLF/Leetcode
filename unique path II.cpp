#include<iostream>
#include<string>
#include<vector>
#include <cctype>
#include<algorithm>
#include<math.h>
using namespace std ;

struct TreeLinkNode {
   int val;
   TreeLinkNode *left, *right, *next;
   TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
};
 
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int> > &obstacleGrid) {
        int m=obstacleGrid.size();
        if(!m)
            return 0;
        int n=obstacleGrid[0].size();
        int A[m][n],i,j;
        for(i=0;i<m;i++)
            for(j=0;j<n;j++)
            {
                if(obstacleGrid[i][j])
                    A[i][j]=0;
                else if((!i)&&(!j))
                    A[i][j]=1;
                else if(!i)
                    A[i][j]=A[i][j-1];
                else if(!j)
                    A[i][j]=A[i-1][j-1];
                else
                    A[i][j]=A[i-1][j]+A[i][j-1];
            }
        return A[m-1][n-1];
    }
    void print()
    {
    	/*
		TreeLinkNode *A,*B,*C,*D,*E,*F,*G;
		A=TreeLinkNode(1);
		B=TreeLinkNode(2);
		C=TreeLinkNode(3);
		D=TreeLinkNode(4);
		E=TreeLinkNode(5);
		F=TreeLinkNode(6);
		G=TreeLinkNode(7);
		*/
		vector<vector<int> > x;
		vector<int>y;
		y.push_back(0);
		x.push_back(y);
		x.push_back(y);
		cout<<uniquePathsWithObstacles(x)<<endl;
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
