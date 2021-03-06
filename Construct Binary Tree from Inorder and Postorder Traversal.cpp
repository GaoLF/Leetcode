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

 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

class Solution {
public:
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
    	
        return build(inorder,postorder,0,inorder.size()-1,0,inorder.size()-1);
    }
    TreeNode* build(vector<int>& in, vector<int> & post, int in_begin, int in_end,int post_begin, int post_end){
    	//int size;
    	int i;
    	int temp;
    	TreeNode *node;
    	
    	if(in_begin>in_end)
    		return NULL;
    //	cout<<pre_begin<<"  "<<pre_end<<" "<<in_begin<<" "<<in_end<<"!!"<<endl;
    	node=new TreeNode(post[post_end]);
    	if(in_begin==in_end)	
    		return node;
		for(temp=post[post_end],i=0;i<=in_end&&in[i+in_begin]!=temp;i++);
		//cout<<i<<"!!!"<<endl;
		node->left=build(in,post,in_begin,in_begin+i-1,post_begin,post_begin+i-1);
		node->right=build(in,post,in_begin+i+1,in_end,post_begin+i,post_end-1);
		return node;
	}
    void print()
    {
    	vector<int> X(11,0),Y(11,0);
    	X[0]=8;
    	X[1]=9;
    	X[2]=4;
    	X[3]=10;
    	X[4]=11;
    	X[5]=5;
    	X[6]=2;
    	X[7]=6;
    	X[8]=7;
    	X[9]=3;
    	X[10]=1;
    	
		Y[0]=8;
    	Y[1]=4;
    	Y[2]=9;
    	Y[3]=2;
    	Y[4]=10;
    	Y[5]=5;
    	Y[6]=11;
    	Y[7]=1;
    	Y[8]=6;
    	Y[9]=3;
    	Y[10]=7;
    	cout<<X.size()<<endl;
    	cout<<Y.size()<<endl;
		TreeNode* A=buildTree(Y,X);
		trans(A);
		cout<<endl;
	}
	void trans(TreeNode *A){
		if(A)
			cout<<A->val<<" ";
		if(A->left)
			trans(A->left);
		if(A->right)	
			trans(A->right);
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
