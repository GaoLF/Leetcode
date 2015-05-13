#include<iostream>
#include<string>
#include<vector>
#include <cctype>
#include<algorithm>
using namespace std;
    
 //* Definition for binary tree
  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };
 
class Solution {
public:
    bool hasPathSum(TreeNode *root, int sum){
		if(!root)
			return 0;
		int flag=0;
        check(root,0,sum,flag);
        return flag;
    }
    int check(TreeNode *a,int sumoftest,int sum,int &flag)
    {
//		cout<<"val:"<<a->val<<" sumoftest:"<<sumoftest<<" flag:"<<flag<<endl ;
		if(a->left)
			check(a->left,sumoftest+a->val,sum,flag);
		if(a->right)
			check(a->right,sumoftest+a->val,sum,flag);
        else if(a->left==NULL&&a->right==NULL)
			if((a->val+sumoftest)==sum)
			{
				flag=1;
			}
			else ;
	}
};
int main()
{
	Solution test;
//	cout<<test.Low("A man, a plan, a canal: Panama")<<endl;
	TreeNode *a;
	TreeNode *b;
	TreeNode *c;
	TreeNode *d;
	TreeNode *e;
	TreeNode *f;
	TreeNode *g;
	a=(TreeNode *)malloc(sizeof(TreeNode));
	b=(TreeNode *)malloc(sizeof(TreeNode));
	c=(TreeNode *)malloc(sizeof(TreeNode));
	d=(TreeNode *)malloc(sizeof(TreeNode));
	e=(TreeNode *)malloc(sizeof(TreeNode));
	f=(TreeNode *)malloc(sizeof(TreeNode));
//	g=(TreeNode *)malloc(sizeof(TreeNode));
//	a=(TreeNode *)malloc(sizeof(TreeNode));
	
	a->left= b;
	a->right=c;
	b->left=d;
	b->right=e;
	c->left= NULL;
	c->right=f;
	d->left= NULL;
	d->right=NULL;
	e->left= NULL;
	e->right=NULL;
	f->left= NULL;
	f->right=NULL;
//	c->left= NULL;
	//c->right=f;
	
	a->val=1;
	b->val=-2;
	c->val=-3;
	d->val=1;	
	e->val=3;
	f->val=-2;
//	test.print(2);
	cout<<test.hasPathSum(a,2)<<endl;
//	cout<<atoi("2147483648")<<endl;
	system("pause");
}
