#include<iostream>
#include<string>
#include<vector>
#include <cctype>
#include<algorithm>
#include<math.h>
using namespace std ;

  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };
 
class Solution {
public:
    TreeNode* fuzhi(TreeNode* root){
    	if(!root)
    		return NULL;
    	TreeNode *res=new TreeNode(root->val);
    	if(root->left)
    		res->left=fuzhi(root->left);
    	if(root->right)
    		res->right=fuzhi(root->right);
    	return res;
	} 
	vector<TreeNode *> generateTrees(int n) {
		int i,j,m,size,count;
		TreeNode *node,*node_cur,*node_iter,*cur;
		vector<TreeNode *> res;
		
		if(!n){
		    res.push_back(NULL);
		    return res;
		}
		node=new TreeNode(1);
		res.push_back(node);
		for(i=2;i<n+1;i++){
			size=res.size();
			for(j=0;j<size;j++){
				//----------将i作为头，（i-1）作为其左 
				node=fuzhi(res[j]);
				node_cur=new TreeNode(i);
				node_cur->left=node;
				res.push_back(node_cur);
				//将i作为右子节点 
				for(node_iter=res[j],count=0;node_iter->right;count++,node_iter=node_iter->right);
				for(;count>=0;count--){
					node=fuzhi(res[j]);
					for(m=0,cur=node;m<count;m++,cur=cur->right);
					node_cur=new TreeNode(i);
					node_cur->left=cur->right;
					cur->right=node_cur;
					res.push_back(node); 
				} 		
			}
			res.erase(res.begin(),res.begin()+size);
		}
		return res;
	}
	/*
	vector<TreeNode *> generateTrees(int n) {
        vector<TreeNode*> res,vec_pre;
        TreeNode *node_to_push,*node_to_insert,*cur;
		int i,j,size;
		
		if(!n)
			return res;
		if(n==1){
			node_to_push=new TreeNode(1);
			res.push_back(node_to_push);
			return res;
		}
		//-------n的左节点是（n-1）的树 
		vec_pre=generateTrees(n-1);
		size=vec_pre.size();
		for(i=0;i<size;i++){
			node_to_push=new TreeNode(n);
			node_to_push->left=vec_pre[i];
			res.push_back(node_to_push);
		}
		
		
		vec_pre=generateTrees(n-1);
		for(i=0;i<size;i++){
			node_to_insert=new TreeNode(n);
			node_to_push=vec_pre[i];
			node_to_insert->left=node_to_push->right;
			node_to_push->right=node_to_insert;
			res.push_back(node_to_push);
		}
		
		vec_pre=generateTrees(n-1);
		for(i=0;i<size;i++){
			node_to_insert=new TreeNode(n);
			node_to_push=vec_pre[i];
			if(node_to_push->right){
				for(cur=node_to_push;cur->right;cur=cur->right);
				cur->right=node_to_insert;
				res.push_back(node_to_push);
			}
		}
		
		return res;
    }
    */
    void print()
    {
    	/*
		TreeNode *A,*B,*C,*D,*E,*F,*G;
		A=TreeNode(1);
		B=TreeNode(2);
		C=TreeNode(3);
		D=TreeLinkNode(4);
		E=TreeLinkNode(5);
		F=TreeLinkNode(6);
		G=TreeLinkNode(7);
		*/
		vector<TreeNode*> res;
		res=generateTrees(4);
		//TreeNode cur;
		for(int i=0;i<res.size();i++){
			trans(res[i]);
			cout<<endl;
		}
	}
	void trans(TreeNode *node){
		if(!node)
			return ;
		cout<<node->val<<" ";
		if(node->left)
			trans(node->left);
		if(node->right)
			trans(node->right);
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
