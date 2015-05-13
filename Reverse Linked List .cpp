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
    ListNode* reverseList(ListNode* head) {
        ListNode *curnode,*newhead,*prenode,*cur;
        if(!head)
            return head;
        
        for(curnode=head,prenode=NULL,newhead=NULL;;){
            if(curnode->next==NULL){
                newhead=curnode;
                curnode->next=prenode;
                return newhead;
            }
            if(curnode!=head){
                cur=curnode->next;
                curnode->next=prenode;
                prenode=curnode;
                curnode=cur;
            }
            else{
                prenode=head;
                curnode=head->next;
                prenode->next=NULL;
            }
        }
    }

    void print()
    {
		ListNode *A=new ListNode(1);
		ListNode *B=new ListNode(2);
		ListNode *C=new ListNode(3);
		ListNode *D=new ListNode(4);
		ListNode *X;
		A->next=B;
		B->next=C;
		C->next=D;
		X=reverseList(A); 
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
