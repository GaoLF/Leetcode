#include<iostream>
#include<string>
#include<vector>
#include <cctype>
#include<algorithm>
#include<math.h>
using namespace std ;

struct TreeNode {
   int val;
   TreeNode *left, *right;
   TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
 
class Solution {
public:
    vector<vector<int> > zigzagLevelOrder(TreeNode *root) {
        int start,count;
		int i,j,size;
		vector<vector<TreeNode *> > res_v;
		vector<vector<int> > res_i;
		vector<TreeNode *> cur_v;
		vector<int> cur_i; 
		bool flag;
	//	TreeNode *cur;
		enum dir{
			l2r=0,r2l
		};
		
		if(!root)
			return res_i;
		cur_v.push_back(root);
		cur_i.push_back(root->val);
		res_v.push_back(cur_v);
		res_i.push_back(cur_i);
		for(flag=l2r,i=0;res_v[i].size();i++){
			size=res_v[i].size();
			cur_v.clear();
			cur_i.clear();
			if(flag==l2r){
				for(j=size-1;j>=0;j--){
					if(res_v[i][j]->right){
						cur_v.push_back(res_v[i][j]->right);
						cur_i.push_back(res_v[i][j]->right->val);
					}
					if(res_v[i][j]->left){
						cur_v.push_back(res_v[i][j]->left);
						cur_i.push_back(res_v[i][j]->left->val);
					}
				}
			}
			else{
				for(j=size-1;j>=0;j--){
					if(res_v[i][j]->left){
						cur_v.push_back(res_v[i][j]->left);
						cur_i.push_back(res_v[i][j]->left->val);
					}
					if(res_v[i][j]->right){
						cur_v.push_back(res_v[i][j]->right);
						cur_i.push_back(res_v[i][j]->right->val);
					}
				}
			}
			if(cur_v.size()){
				res_v.push_back(cur_v);
				res_i.push_back(cur_i);
			}
			else
				break;
			flag=flag^1;
		}
		return res_i;
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
		TreeNode A(1),B(2),C(3),D(4),E(5),F(6),G(7);

		vector<vector<int> > res;
		res=zigzagLevelOrder(&A);
		for(int i=0;i<res.size();i++){
			for(int j=0;j<res[i].size();j++)
				cout<<res[i][j];
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
