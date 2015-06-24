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
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int> > res;
        vector<int >temp;
		check(1,9,k,res,temp,n);
        return res;
    }
    void check(int begin,int end,int k,vector<vector<int> > &res,vector<int> vec,int rest){
		//cout<<begin<<" "<<end<<" "<<k<<" "<<rest<<endl;
		if(k==1&&rest>=begin&&rest<=end){
			vec.push_back(rest);
			res.push_back(vec);
		}
		else if(k>0&&(rest>=begin)){
			check(begin+1,end,k,res,vec,rest);
			vec.push_back(begin);
			check(begin+1,end,k-1,res,vec,rest-begin);
		}
	}
    void print()
    {
		vector<vector<int> >res;
		res=combinationSum3(3,8);
		for(int i=0;i<res.size();i++){
			for(int j=0;j<res[i].size();j++)
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
