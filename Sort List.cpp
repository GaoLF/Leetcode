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
	ListNode(int x) : val(x), next(NULL) {}
} ListNode;
class Solution {
public:
    ListNode* sortList(ListNode* head) {
        if(head==NULL||head->next==NULL)
			return head;
		int size=1,small_len;
		for(ListNode*temp=head;temp->next;temp=temp->next) 
			size++;
		//temp=head;
		qsort(head,size);
		return head;
    }
    void qsort(ListNode* begin, int size){
    	if(size<=1)	
    		return;
    	int small_len=0;
    	ListNode* sec_begin=partition(begin,size,small_len);
    	cout<<"( "<<small_len<<" )"<<" -> "<<sec_begin->val<<" <- "<<"( "<<size-small_len-1<<" )"<<endl;
    	qsort(begin,small_len);
    	qsort(sec_begin,size-small_len-1);
	}
	ListNode* partition(ListNode *begin,int size,int &small_len){
		int cur=begin->val;
		int i;
		ListNode *sec_begin=begin;
		for(i=0;i<size;i++){
			if(begin->val<cur){
				swap(sec_begin->val,begin->val);
				sec_begin=sec_begin->next;
				small_len++;
			}
			begin=begin->next;
		}
		sec_begin->val=cur;
		sec_begin=sec_begin->next;
		return sec_begin;
	}

    void print()
    {
		ListNode *A=new ListNode(1);
		ListNode *B=new ListNode(3);
		ListNode *C=new ListNode(3);
		ListNode *D=new ListNode(1);
		ListNode *E=new ListNode(3);
		ListNode *F=new ListNode(1);
		ListNode *G=new ListNode(3);
		ListNode *H=new ListNode(3);
		ListNode *I=new ListNode(2);
		ListNode *J=new ListNode(3);
		ListNode *K=new ListNode(2);
		ListNode *L=new ListNode(2);
		ListNode *M=new ListNode(1);
		ListNode *N=new ListNode(1);

		A->next=B;
		B->next=C;
		C->next=D;
		D->next=E;
		E->next=F;
		F->next=G;
		G->next=H;
		H->next=I;
		I->next=J;
		J->next=K;
		K->next=L;
		L->next=M;
		M->next=N;

		A=sortList(A);
		for(ListNode* temp=A;temp;temp=temp->next)
			cout<<temp->val<<" ";
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
