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
private:
	vector<TreeNode*> s;
public:
    void recoverTree(TreeNode* root) {
		fillstack(root);
		TreeNode *foo=NULL,*bar=NULL;
		int i,size=s.size();
		int flag=0;
		
		for(i=0;i+1<size;i++){
			if(!flag&&s[i]->val>s[i+1]->val){
				foo=s[i];
				bar=s[i+1];
				flag=1;
				continue;
			}
			if(flag&&s[i]->val>s[i+1]->val){
				bar=s[i+1];
				break;
			}
		}
		if(foo&&bar)
			swap(foo->val,bar->val);
		
    }
    void fillstack(TreeNode *root){
    	if(root){
    		if(root->left)
    			fillstack(root->left);
    		s.push_back(root);
    		if(root->right)
    			fillstack(root->right);
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
		TreeNode *A=new TreeNode(13);
		TreeNode *B=new TreeNode(7);
		TreeNode *C=new TreeNode(8);
		TreeNode *D=new TreeNode(9);
		TreeNode *E=new TreeNode(10);
		TreeNode *F=new TreeNode(4);
		TreeNode *G=new TreeNode(15);
		TreeNode *H=new TreeNode(19);
		TreeNode *I=new TreeNode(20);
		TreeNode *head=F;
		F->left=B;
		F->right=H;
		B->left=A;
		B->right=D;
		D->left=C;
		D->right=E;
		H->left=G;
		H->right=I;
		recoverTree(head);
		cout<<A->val<<endl;
		cout<<F->val<<endl;
		
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
