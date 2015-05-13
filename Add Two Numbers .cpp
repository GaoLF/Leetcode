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
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *res,*node,*cur;
        int headflag=1,foo=0,sum;
        res=(ListNode*)malloc(sizeof(ListNode));
        cur=res;
		
		while(l1||l2){	
			if(l1&&l2){	
				sum=l1->val+l2->val;	
				l1=l1->next;
				l2=l2->next;
			}
			else if(l1){
				sum=l1->val;
				l1=l1->next;
			}
			else{
				sum=l2->val;
				l2=l2->next;
			}
			sum+=foo;
			if(sum>9){
				sum=sum%10;
				foo=1;
			}
			else
				foo=0;
			if(headflag){
				res->val=sum;
				headflag=0;
			}
			else{
				node=(ListNode*)malloc(sizeof(ListNode));
				node->val=sum;
				node->next=NULL;
				res->next=node;
				res=res->next;
			}
		} 
		if(foo){
			node=(ListNode*)malloc(sizeof(ListNode));
			node->val=sum;
			node->next=NULL;
			res->next=node;
		}
	//	cout<<res->val<<endl;
        return cur;
    }

    void print()
    {
		ListNode *A,*B,*C,*a,*b,*c,*res;
		A=(ListNode*)malloc(sizeof(ListNode));
		B=(ListNode*)malloc(sizeof(ListNode));
		C=(ListNode*)malloc(sizeof(ListNode));
		a=(ListNode*)malloc(sizeof(ListNode));
		b=(ListNode*)malloc(sizeof(ListNode));
		c=(ListNode*)malloc(sizeof(ListNode));
		A->val=2;
		B->val=4;
		C->val=3;
		a->val=5;
		b->val=6;
		c->val=4;
		A->next=B;
		B->next=C;
		C->next=NULL;
		a->next=b;
		b->next=c;
		c->next=NULL;
		res=addTwoNumbers(A,a);
		cout<<res->val<<endl;
		B=res->next;
		cout<<B->val<<endl;
		cout<<res->next->next->val<<endl;
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
