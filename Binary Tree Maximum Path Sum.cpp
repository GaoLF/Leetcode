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
	int maxPathSum(TreeNode* root) {
    	if(!root)
    		return 0;
        static int res=root->val;
		
        return res;
    }
	int check(TreeNode* r,int &res){
		int left=0,right=0;
		if(r->left)
			left=check(r->left,res);
		if(r->right)
			right=check(r->right,res);
		res=max(res,left+right+r->val);
		return 	max(0,max(0,max(left,right))+r->val);	
	}
    void print()
    {
		TreeNode *A=new TreeNode(1);
		TreeNode *B=new TreeNode(2);
		TreeNode *C=new TreeNode(-3);
		A->left=B;
		A->right=C;
		cout<<maxPathSum(A)<<endl;
		cout<<maxPathSum(B)<<endl;
		cout<<maxPathSum(C)<<endl;
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
