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
 
 //* Definition for binary tree
struct TreeNode {
     int val;
     struct TreeNode *left;
     struct TreeNode *right;
     TreeNode(int x) :val(x),left(NULL),right(NULL){}
};

class Solution {
public:
	int *postorderTraversal(struct TreeNode *root, int *returnSize) {
    	int i=0;
    	if(root)
    		travel(root,returnSize);
    	x[i]='\0';
    	return x;
	}		
	int travel(struct TreeNode *root,int *x){
		if(root->left)
			travel(root->left,x);
		if(root->right)
			travel(root->right,x);
		x++;
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
		int res[65536]={0};
		res=postorderTraversal(&A);
		for(int i=0;res[i];i++)
			cout<<res[i]<<" ";
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
