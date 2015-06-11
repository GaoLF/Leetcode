#include<iostream>
#include<string>
#include<vector>
#include <cctype>
#include<algorithm>
#include<math.h>
using namespace std ;

typedef struct TreeLinkNode {
   int val;
   TreeLinkNode *left, *right, *next;
   TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
}TreeNode;
 
class Solution {
public:
    int countNodes(TreeNode* root) {
        int res=0;
        if(!root)
        	return 0;
        int left=0,right=0;
		for(TreeNode* temp=root;temp;temp=temp->left,left++);
		for(TreeNode* temp=root;temp;temp=temp->right,right++);
		if(left==right)
			return pow(2,left)-1;
        return 1+countNodes(root->left)+countNodes(root->right);
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
		cout<<countNodes(&A)<<endl;
		
		cout<<countNodes(NULL)<<endl;
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
