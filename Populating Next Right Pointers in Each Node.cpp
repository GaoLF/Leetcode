#include<iostream>
#include<string>
#include<vector>
#include <cctype>
#include<algorithm>
using namespace std ;
struct TreeLinkNode{
	int val;
	TreeLinkNode * left,*right,*next;
};
class Solution {
public:
	void connect(TreeLinkNode *root) {
//        if(!root)
//            return root;
        if(root)
        {
            TreeLinkNode *cur,*pp;
//            pp=TreeLinkNode();
            pp=NULL;
            cur=root;
            int depth=0;
            while(cur->left)
            {
                depth++;
                popul(root,depth,pp,0);
                cur=cur->left;
            }
        }
    }
    void popul(TreeLinkNode *& root,int depth,TreeLinkNode * &cur,int i)
    {
        if(i==depth-1)
        {
            root->left->next=root->right;
            if(cur!=NULL)
                cur->next=root->left;
 //           cur=(TreeLinkNode*)malloc(sizeof(TreeLinkNode));
            cur=root->right;
        }
        else
        {
            popul(root->left,depth,cur,i+1);
            popul(root->right,depth,cur,i+1);
        }
    }
	void print()
	{
		TreeLinkNode *x,*y,*z,*a,*b,*c,*d;
		x=new TreeLinkNode;
		y=new TreeLinkNode;
		z=new TreeLinkNode;
		a=new TreeLinkNode;
		b=new TreeLinkNode;
		c=new TreeLinkNode;
		d=new TreeLinkNode;
		x->left=y;
		x->right=z;
		y->left=a;
		y->right=b;
		z->left=c;
		z->right=d;
		a->left=NULL;
		a->right=NULL;
		b->left=NULL;
		b->right=NULL;
		c->left=NULL;
		c->right=NULL;
		d->left=NULL;
		d->right=NULL;
		
		x->val=1;
		y->val=2;
		z->val=3; 
		a->val=4;
		b->val=5;
		c->val=6;
		d->val=7;
		connect(x);
		cout<<d->next->val<<endl;
//		x.push_back(7);

//		x.push_back(9);
//		cout<<maxProfit(x)<<endl;
//		cout<<x.size()<<endl;
//		x.erase(x.begin());
//		cout<<x.size()<<endl;
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
