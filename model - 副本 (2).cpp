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
	void connect(TreeLinkNode *root) {
		if(!root)
			return;
		deal_left(root);
		deal_right(root);
	}
	void deal_left(TreeLinkNode *root){
		if(root->left){
			root->left->next=root->right;
		}
		deal_left(root->left);
		deal_right(root->right); 
	}
	void deal_right(TreeLinkNode *root){
		if(root->left){
			if(root->next&&root->next->left)
				root->right->next=root->next->left;
		}
		deal_right(root->left);
		deal_right(root->right);
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
		TreeLinkNode A(1),B(2),C(3),D(4),E(5),F(6),G(7);
		A.left=&B;
		A.right=&C;
		B.left=&D;
		B.right=&E;
		C.left=&F;
		C.right=&G;
		connect(&A);
		cout<<B.next->val<<endl;
		
		cout<<D.next->val<<endl;
		
		cout<<E.next->val<<endl;
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
