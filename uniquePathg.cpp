#include<iostream>
#include<string>
#include<vector>
#include <cctype>
#include<algorithm>
using namespace std ;
struct ListNode{
	int val;
	ListNode *next;
	ListNode(int x):val(x),next(NULL){}
};
class Solution {
public:
	bool cmp(int a,int b)
	{
    	return a>b;
	}
    ListNode *swapPairs(ListNode *head) {
        ListNode *res=head;
        ListNode *cur,*cur2;
        if(!head)
            return res;
        if(head->next)
        {
            cur2=head->next->next;
            res=head->next;
            res->next=head;
            cur=head;
            if(cur2)
                head=cur2;
            else
                head=NULL;
            res->next->next=head;
        }
        else
        	return head;
        while(head)//head是当前节点，cur是当前节点的前一个节点
        {
            if(head->next)
            {
                cur2=head->next->next;
                cur->next=head->next;
                cur->next->next=head;
                cur=head;
                if(cur2)
                    head=cur2;
                else
                    head=NULL;
                cur->next=head;
            }
            else
            {
				cur->next=head;
                head=NULL;
			}
            
            
        }
        return res;
    }
    void print()
    {
		ListNode *a,*b,*c,*d,*e,*f,*g;
		a=(ListNode*)malloc(sizeof(ListNode));
		b=(ListNode*)malloc(sizeof(ListNode));
		c=(ListNode*)malloc(sizeof(ListNode));
		d=(ListNode*)malloc(sizeof(ListNode));
		a->val=1;
		b->val=2;
		c->val=3;
//		d->val=4;
		a->next=b;
//		b->next=c;
//		c->next=d;
		a->next=NULL;
		for(ListNode *x=a;x;x=x->next)
			cout<<x->val;
		cout<<endl;
		a=swapPairs(a);
		for(ListNode *x=a;x;x=x->next)
			cout<<x->val;
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
