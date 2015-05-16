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
	ListNode(int x):val(x),next(NULL){}
} ListNode;
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        int i;
        ListNode *begin,*foo,*bar,*begin2next,*temp;
        
        if(!head)
        	return NULL;
        for(i=0,begin=head;i+2<m;i++,begin=begin->next);
        
        if(m==1)
			temp=begin2next=begin;
		else
			begin2next=temp=begin->next;
		foo=begin2next->next; 
		for(i=0;i<(n-m);i++){
        	bar=foo->next;
        	foo->next=temp;
        	temp=foo;
        	foo=bar;
		}
		if(m==1)
			head=temp;
		else
			begin->next=temp;
		begin2next->next=foo;
		
		return head;
    }

    void print()
    {
		//ListNode* A=new ListNode(1);
		ListNode* A=new ListNode(1);
		ListNode* B=new ListNode(2);
		ListNode* C=new ListNode(3);
		ListNode* D=new ListNode(4);
		ListNode* E=new ListNode(5);
	//	A->next=B;
	//	B->next=C;
	//	C->next=D;
	//	D->next=E;
		//rotateRight
		ListNode* x=reverseBetween(A,1,1);
	//	ListNode* x=A;
	//	for(int i=0;i<10;i++){
	//		x=rotateRight(x,i);
			for(x;x;x=x->next)
				cout<<x->val<<" ";
			cout<<endl;
	//	}

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
