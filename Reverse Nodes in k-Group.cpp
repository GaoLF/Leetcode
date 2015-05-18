#include<iostream>
#include<string>
#include<vector>
#include <cctype>
#include<algorithm>
#include<math.h>
#include<stack>
using namespace std ;
typedef struct ListNode{
	int val;
	ListNode * next;
	ListNode(int x) : val(x), next(NULL) {}
} ListNode;
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        stack<ListNode*> s;
		int i,j,headflag=0;
		ListNode *temp,*pre,*begin,*nextnode;
		
		if(head==NULL||k<1)
			return head;
		for(begin=pre=head;begin;){
			for(i=0,temp=begin;i<k;i++){
				if(temp==NULL){
					break;
				}
				else{
					s.push(temp);
					temp=temp->next;
				}
			}
			nextnode=temp;
			if(s.size()==k){
				temp=begin=s.top();
				s.pop();
				while(!s.empty()){
					temp->next=s.top();
					temp=temp->next;
					s.pop();
				}
				temp->next=nextnode;
			//	begin=nextnode;
			}
			else
				break;
			if(headflag==0){
				head=begin;
				headflag=1;
			}
			else
				pre->next=begin;
			pre=temp;
			begin=nextnode;		
		} 
		return head;
    }

    void print()
    {
    	ListNode* A=new ListNode(1);
    	ListNode* B=new ListNode(2);
    	ListNode* C=new ListNode(3);
    	ListNode* D=new ListNode(4);
    	ListNode* E=new ListNode(5);
    	ListNode* F=new ListNode(6);
    	ListNode* G=new ListNode(7);
		A->next=B;
		B->next=C;
		C->next=D;
		D->next=E;
		E->next=F;
		F->next=G;
		ListNode* X=reverseKGroup(A,8);
		for(;X;X=X->next)
			cout<<X->val<<" ";
		cout<<endl;

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
