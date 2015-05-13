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
         TreeNode *res; 
         vector<int> in,po;
         int cur;
		 size_t i;
         vector<int>::iterator iter;
         
         if(inorder.size()==0)
         	return NULL;
         res=(TreeNode*)malloc(sizeof(TreeNode));
         res->val=*(postorder.end()-1);
         if(inorder.size()==1){
         	res->left=NULL;
         	res->right=NULL;
         	return res;
		 }
		 cur=postorder[postorder.size()-1];
         for(i=0;inorder[i]!=cur;i++);
         in.insert(in.begin(),inorder.begin(),inorder.begin()+i);
         po.insert(po.begin(),postorder.begin(),postorder.begin()+i);

		 res->left=buildTree(in,po);
         
         if(i==inorder.size()){
			res->right=NULL;
			return res;         	
		 }
		 in.clear();
		 po.clear();
		 in.insert(in.begin(),inorder.begin()+i+1,inorder.end());
		 po.insert(po.begin(),postorder.begin()+i,postorder.end()-1);
		 res->right=buildTree(in,po);
		 
		 return res;
    }
    void print()
    {
		TreeNode *A;
		vector<int> in,po;
		in.push_back(-4);
		in.push_back(-10);
		in.push_back(3);
		in.push_back(-1);
		in.push_back(7);
		in.push_back(11);
		in.push_back(-8);
		in.push_back(2);
		
		po.push_back(-4);
		po.push_back(-1);
		po.push_back(3);
		po.push_back(-10);
		po.push_back(11);
		po.push_back(-8);
		po.push_back(2);
		po.push_back(7);
	
		A=buildTree(in,po); 
		echo(A);
	}
	void echo(TreeNode *A){
		if(A->left)
			echo(A->left);
		cout<<A->val<<" ";
		if(A->right)
			echo(A->right);
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
