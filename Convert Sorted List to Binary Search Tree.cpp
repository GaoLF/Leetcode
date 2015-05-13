#include<iostream>
#include<string>
#include<vector>
#include <cctype>
#include<algorithm>
#include<math.h>
using namespace std ;

  struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
  };
 


struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
 
class Solution {
public:
    TreeNode *sortedListToBST(ListNode *head) {
        int *array,i,size;
        ListNode *curnode;
        for(size=0,curnode=head;curnode;size++,curnode=curnode->next);
        array=(int*)malloc(sizeof(int)*(size+1));
        for(i=0,curnode=head;curnode;i++,curnode=curnode->next){
        	array[i]=curnode->val;
		}
		return buildBST(array,0,size-1);
    }
    TreeNode* buildBST(int *array,int begin,int end){
    	TreeNode *node;
		int middle=(begin+end+1)/2;
		node=(TreeNode*)malloc(sizeof(TreeNode));
		if(begin==end){
    		node->val=array[begin];
    		node->left=NULL;
			node->right=NULL;
    		return node;
		}
		if(begin>end)
			return NULL;
		node->val=array[middle];
		node->left=buildBST(array,begin,middle-1);
		node->right=buildBST(array,middle+1,end);
		return node;
	} 
    void print(){
		ListNode A(0),B(1),C(2),D(3),E(4);
		A.next=NULL;//&B;
		B.next=&C;
		C.next=&D;
		D.next=&E;
		TreeNode *res=sortedListToBST(&A);
		cout<<res->val<<endl;
	//	cout<<res->left->val<<endl;
	//	cout<<res->left->val<<endl; 
	//	cout<<res->left->val<<endl; 
	//	cout<<res->left->val<<endl;  
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
