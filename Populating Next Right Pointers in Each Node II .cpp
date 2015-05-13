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
		vector<TreeLinkNode*> stack;
		int count=1,i=0,size;
		if(!root)
			return ;
		stack.push_back(root);
		while(count){
			count=0;
			size=stack.size(); 
			for(;i<size;i++){
				if(i<size-1)
					stack[i]->next=stack[i+1];
				if(stack[i]->left){
					stack.push_back(stack[i]->left);
					count++;
				}
				if(stack[i]->right){
					stack.push_back(stack[i]->right);
					count++;
				}
			}
	//		i=size;
		}
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
