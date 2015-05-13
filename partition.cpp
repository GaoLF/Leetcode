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
    ListNode *partition(ListNode *head, int x) {
        ListNode *less,*cur,*curless,*curhead,*pre,*tail;
        if(!head||!(head->next))
            return head;
//        curhead=(ListNode*)malloc(sizeof(ListNode));
        curhead=NULL;
        for(cur=head,pre=head;cur;)
        {
            if(cur->val<x)
            {
                
                curless=(ListNode*)malloc(sizeof(ListNode));
                curless->val=cur->val;
                curless->next=NULL;
                if(!curhead)
                {
                    curhead=curless;
                    less=curhead;
                }
                else
                {
                    less->next=curless;   
                    less=curless;
                }
                if(cur==head)
                {
                    head=cur->next;
                    cur=head;
                    pre=head;
                }
                else
                {
                    pre->next=cur->next;
                    cur=cur->next;
                }
            }
            else
            {
				if(cur==head)
                {
                    cur=cur->next;
                }
                else
                {
                    cur=cur->next;
                    pre=pre->next;
                }
            }
        }
        if(!head)
        	return curhead;
        
        if(head->val>=x)
        	cur=head;
        else
        {
			for(cur=head;cur->next&&cur->next->val>=x;cur=cur->next);
		}
				
        for(less=curhead;less;less=less->next)
            tail=less;
        if(cur==head)
        {
			if(curhead)
			{
				tail->next=head;
				head=curhead;
			}
		}
        else if(cur->next)
        {
            if(curhead)
            {
                tail->next=cur->next;
                cur->next=curhead;
            }
        }
        return head;
    }

    void print()
    {
		vector<vector <int> > x;
		vector<int> y;
		y.push_back(2);
		y.push_back(3);
		y.push_back(6);
		y.push_back(7);
//		y.push_back(2);
		//x.push_back(y);
		int P[13]={0,1,0,2,1,0,1,3,2,1,2,1};
		int Q[4]={4,2,3};
		int M[11]={5,5,1,7,1,1,5,2,7,6};
//		isValid("[({(())}[()])]");

		ListNode *A,*B,*C,*D,*E,*F,*res;
		A=(ListNode*)malloc(sizeof(ListNode));
		B=(ListNode*)malloc(sizeof(ListNode));
		C=(ListNode*)malloc(sizeof(ListNode));
		D=(ListNode*)malloc(sizeof(ListNode));
		E=(ListNode*)malloc(sizeof(ListNode));
		F=(ListNode*)malloc(sizeof(ListNode));

		A->val=1;
		B->val=4;
		C->val=3;
		D->val=2;
		E->val=5;
		F->val=2;
		A->next=B;
		B->next=C;
		C->next=D;
		D->next=E;
		E->next=F;
		F->next=NULL;
//		D->next=NULL;
		res=partition(A,3);
		for(res;res;res=res=res->next)
			cout<<res->val<<" ";
		cout<<endl;

		
		//cout<<trailingZeroes(625)<<endl;
		//cout<<x.size()<<endl;
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
