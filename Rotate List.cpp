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
	ListNode(int x):val(x),next(NULL){}
} ListNode;
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        int i,j,size;
		ListNode *temp,*foo; 
		
		if(!head)
			return head;
		for(size=0,temp=head;temp;temp=temp->next,size++);
		k=k%size;		
		if(!k)
			return head;
		for(temp=head,i=0;i+1<(size-k);i++,temp=temp->next);
		foo=temp->next;
	//	cout<<size<<" "<<k<<" "<<temp->val<<" "<<foo->val<<endl;
		temp->next=NULL;
		for(temp=foo;temp->next;temp=temp->next);
		temp->next=head;
		head=foo;
		
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
		A->next=B;
		B->next=C;
		C->next=D;
		D->next=E;
		//rotateRight
		ListNode* x=rotateRight(A,6);
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
