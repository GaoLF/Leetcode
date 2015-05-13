#include<iostream>
#include<string>
#include<vector>
#include <cctype>
#include<algorithm>
using namespace std ;
class Solution {
public:
    TreeNode *sortedArrayToBST(vector<int> &num) {
		int size=num.size();
        if(!size)
        	return NULL;
        TreeNode *Tree;
        vector<int>::iterator iter;
		Tree=(TreeNode*)malloc(sizeof(TreeNode)); 
		Tree.val=num[size/2];
		vector<int> leftTree,rightTree;
		if(size/2==1)
			Tree.left=NULL;
		else
		{
			iter=leftTree.begin();
			leftTree.insert(iter,num.begin(),num.begin()+size/2);
			Tree.left=sortedArrayToBST(leftTree);
		}
		if(size/2==size-1)
			Tree.right=NULL;
		else
		{
			iter=rightTree.begin();
			rightTree.insert(iter,num.begin()+size/2+1,num.end()); 	
			Tree.right=sortedArrayToBST(rightTree);     	
		}
		return Tree;
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
