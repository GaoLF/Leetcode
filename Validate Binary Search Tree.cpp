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
    bool isValidBST(TreeNode* root) {
        vector<int> sortlist;
        fill_List(root,sortlist);
        if(!root)
        	return 0;
        for(int i=0;i+1<sortlist.size();i++){
        	if(sortlist[i]>sortlist[i+1])
        		return 0;
		}
		return 1;
    }
    void fill_List(TreeNode* r,vector<int> &l){
    	if(r){
    		if(r->left)
    			fill_List(r->left,l);
    		l.push_back(r->val);
    		if(r->right)
    			fill_List(r->right,l);
		}
	}

    void print()
    {
		TreeNode *A= new TreeNode(5);
		TreeNode *B= new TreeNode(2);
		TreeNode *C= new TreeNode(3);
		TreeNode *D= new TreeNode(4);
		C->left=A;
		A->right=B;
		C->right=D;
		cout<<isValidBST(C)<<endl;
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
