#include<iostream>
#include<string>
#include<vector>
#include <cctype>
#include<algorithm>
using namespace std ;
struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
    ListNode *removeNthFromEnd(ListNode *head, int n) {
		ListNode *cur;
		cur=head;
		while(cur)
		{
			ListNode *cur2=cur;
			ListNode *cur3;
			for(int i=0;i<n;i++)
				cur2=cur2->next;
			if(!cur2)
			{
				if(cur==head)
				{
					head=head->next;break;
				}
				else
				{
					cur3->next=cur->next;break;
				}
		 	}
	 		cur3=cur;
			cur=cur->next; 
		}
		return head;
    }
    void print()
    {
		ListNode *a,*b,*c;
		a=(ListNode*)malloc(sizeof(ListNode));
		b=(ListNode*)malloc(sizeof(ListNode));
		c=(ListNode*)malloc(sizeof(ListNode));
		a->val=1;
		b->val=2;
		c->val=3;
		a->next=b;
		b->next=c;
		c->next=NULL;
		a=removeNthFromEnd(a,3);
		while(a)
		{
			cout<<a->val<<endl;
			a=a->next;
		}
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
