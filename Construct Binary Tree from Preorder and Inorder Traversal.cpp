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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
    	
        return build(preorder,inorder,0,preorder.size()-1,0,preorder.size()-1);
    }
    TreeNode* build(vector<int>& pre, vector<int> & in, int pre_begin, int pre_end,int in_begin, int in_end){
    	//int size;
    	int i;
    	int temp;
    	TreeNode *node;
    	
    	if(pre_begin>pre_end)
    		return NULL;
    //	cout<<pre_begin<<"  "<<pre_end<<" "<<in_begin<<" "<<in_end<<"!!"<<endl;
    	if(pre_begin>10)
    		return NULL;
    	node=new TreeNode(pre[pre_begin]);
    	if(pre_begin==pre_end)	
    		return node;
		for(temp=pre[pre_begin],i=0;i<=in_end&&in[i+in_begin]!=temp;i++);
		//cout<<i<<"!!!"<<endl;
		node->left=build(pre,in,pre_begin+1,pre_begin+i,in_begin,in_begin+i-1);
		node->right=build(pre,in,pre_begin+i+1,pre_end,in_begin+i+1,in_end);
		return node;
	}
    void print()
    {
    	vector<int> X(11,0),Y(11,0);
    	X[0]=1;
    	X[1]=2;
    	X[2]=4;
    	X[3]=8;
    	X[4]=9;
    	X[5]=5;
    	X[6]=10;
    	X[7]=11;
    	X[8]=3;
    	X[9]=6;
    	X[10]=7;
    	
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
		TreeNode* A=buildTree(X,Y);
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
