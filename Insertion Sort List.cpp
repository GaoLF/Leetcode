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
 
class Solution {
public:
    ListNode *insertionSortList(ListNode *head) {
        ListNode *node,*iter,*cur;
        int flag=1;
        if(!head)
            return head;
        for(iter=head;iter->next;){		
			if(iter->next->val<head->val){
				cur=iter->next->next;
				iter->next->next=head;	
				head=iter->next;
				iter->next=cur; 
				continue;
			}
        	for(node=head,flag=1;node->next!=iter->next;node=node->next){
				if(iter->next->val<node->next->val){
					flag=0;
					cur=iter->next->next;
					iter->next->next=node->next;
					node->next=iter->next;
					iter->next=cur;
					break;
				}
			}
			if(flag)
				iter=iter->next;
			
		}
		return head;
    }
    void print()
    {
    	/*
		TreeLinkNode *A,*B,*C,*D,*E,*F,*G;
		A=TreeLinkNode(1);
		B=TreeLinkNode(2);
		C=TreeLinkNode(3);
		D=TreeLinkNode(4);
		E=TreeLinkNode(5);
		F=TreeLinkNode(6);
		G=TreeLinkNode(7);
		*/
		ListNode A(4),B(2),C(1),D(3),E(1),F(6),G(7);
//		A=NULL;
		A.next=&B;
		B.next=&C;
		C.next=&D;
		D.next=NULL;
		E.next=NULL;
		ListNode *X;
		X=insertionSortList(&A);
		for(;X;X=X->next){
			cout<<X->val<<endl;
		}
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
