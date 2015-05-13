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
    void reorderList(ListNode* head) {
        stack<ListNode*> second;
        ListNode *temp,*cur;
        int i,size;
        if(head==NULL||head->next==NULL)
        	return;
        for(temp=head;temp;temp=temp->next){
        	second.push(temp);
		}
		cout<<second.size()<<endl;
		size=second.size();
	//	for(i=0,temp=head;i<(size)/2;i++,temp=temp->next);
	//	temp->next=NULL;
		for(i=0,temp=head;i<(size)/2;i++){
			cur=second.top();
			second.pop();
			cur->next=temp->next;
			temp->next=cur;
			temp=cur->next;
			if(i+1>=size/2){
				if(size%2)
					cur->next->next=NULL;
				else
					cur->next=NULL;
			}
				 
		}
		
	//temp
    }

    void print()
    {
		ListNode *A=new ListNode(1);
		ListNode *B=new ListNode(2);
		ListNode *C=new ListNode(3);
		ListNode *D=new ListNode(4);
		ListNode *E=new ListNode(5);
		A->next=B;
		B->next=C;
		C->next=D;
		D->next=E;
		reorderList(A);
		for(ListNode *temp=A;temp;temp=temp->next){
			cout<<temp->val<<" ";
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
