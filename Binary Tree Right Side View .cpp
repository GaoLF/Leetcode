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
struct TreeNode {
   int val;
   TreeNode *left;
   TreeNode *right;
   TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
public:
    vector<int> rightSideView(TreeNode *root) {
        int res_cur,count_cur;
		int iter,count,start;
		vector<TreeNode*> stack;
		vector<int> res;
		
		if(!root)
			return res;
		stack.push_back(root);
		res.push_back(root->val);	
		for(start=0,count=1;count;){
			count_cur=0;
			for(iter=start;iter<start+count;iter++){
				if(stack[iter]->left){
					count_cur++;
					res_cur=stack[iter]->left->val;
					stack.push_back(stack[iter]->left);
				}
				if(stack[iter]->right){
					count_cur++;
					res_cur=stack[iter]->right->val;
					stack.push_back(stack[iter]->right);
				}
			}
			start+=count;
			//cout<<"start: "<<start<<"count_cur: "<<count_cur<<"count: "<<count<<endl;
			count=count_cur;
			
			if(count)
				res.push_back(res_cur);
		}
		return res;
		 
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
		A.left=&B;
		A.right=&C;
		B.left=&D;
		B.right=&E;
		C.left=&F;
		C.right=&G;
		
		vector<int> x;
		x=rightSideView(&A);
		
		for(int i=0;i<x.size();i++){
			cout<<x[i]<<" ";
		}
		cout<<endl;
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
