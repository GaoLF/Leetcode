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
    vector<vector<int> > subsetsWithDup(vector<int> &S) {
        vector<vector<int> > res;
        vector<vector<int> >::iterator iter;
        vector<int> cur;
        res.push_back(cur);
		deal(S,0,res);
		for(int i=0;i<res.size();i++){
			sort(res[i].begin(),res[i].end());
		}
		sort(res.begin(),res.end());
		iter=unique(res.begin(),res.end());
		res.erase(iter,res.end());
		return res;
    }
    void deal(vector<int> &s,int iter,vector<vector<int> >& res){
    	if(iter>=s.size())
    		return ;
    	int size=res.size();
    	int i,j;
    	vector<int> cur;
    	for(i=0;i<size;i++){
			cur=res[i];
			cur.push_back(s[iter]);
    		res.push_back(cur);    		
		}
		deal(s,iter+1,res);
	}

    void print()
    {
		vector<int> A;
		A.push_back(1);
		A.push_back(2);
		A.push_back(2);
		vector<vector<int> > B;
		B=subsetsWithDup(A);
		for(int i=0;i<B.size();i++){
			for(int j=0;j<B[i].size();j++)
				cout<<B[i][j]<<" ";
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
