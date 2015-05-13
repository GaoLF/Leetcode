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
    vector<vector<int> > generateMatrix(int n) {
        vector<vector<int> > res;
		vector<int> foo;
		int i,j,sum,bar;
		enum dir{
			right=0,down,left,up,sumofdir
		};
		
		if(!n)
			return res;
		for(i=0;i<n;i++)
			foo.push_back(0);
		for(i=0;i<n;i++)
			res.push_back(foo);
		for(sum=1,bar=right,i=0,j=0;sum<=n*n;){
			if(bar==right){
				for(;j<n-i;j++)
					res[i][j]=(sum++);
				j--;i++;
			}
			else if(bar==down){
				for(;i<(j+1);i++)
					res[i][j]=(sum++);
				i--;j--;
			}
			else if(bar==left){
				for(;j>(n-i-2);j--)
					res[i][j]=(sum++);
				j++;i--;
				}
			else{
			//	cout<<i<<" "<<j;
				for(;i>j;i--)
					res[i][j]=(sum++);
				i++;j++;
			//	cout<<i<<" "<<j;
				}
			bar=(bar+1)%sumofdir;
		}
		return res;
    }
    void print()
    {
		vector<vector<int> > res;
		int n=8;
		res=generateMatrix(n);
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++)
				cout<<res[i][j]<<" ";
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
