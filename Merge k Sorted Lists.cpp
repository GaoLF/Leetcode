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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* res;
        int size=lists.size();
        int i,num;
		while(size!=1){
        	num=size/2;
        	vector<ListNode*>::iterator iter,iter2;
    		iter=lists.begin();
    		iter2=iter+num;
        	for(i=0;i<num;i++){
        		*iter=merge(*iter,*iter2);
        		iter++;
        		iter2=lists.erase(iter2);
			}
        	if(size%2==1){
        		*(lists.begin())=merge(*(lists.begin()),*iter2);  		
        		lists.erase(iter2);
			}	
        	size=lists.size();
		}
		
        return lists[0]; 
    }
    ListNode* merge(ListNode* s1,ListNode* s2){
    	ListNode *head=new ListNode(0);
    	ListNode *temp=head;

    	while(s1&&s2){
    		if(s1->val<s2->val){
    			temp->next=s1;
    			s1=s1->next;
			}
			else{
				temp->next=s2;
				s2=s2->next;
			}
			temp=temp->next;
		}
		if(!s1)
    			temp->next=s2;
    	else 
    			temp->next=s1;
		
    	return head->next;
	}

    void print()
    {
    	ListNode* A=new ListNode(2);
		ListNode* B=new ListNode(3);
		ListNode* C=new ListNode(5);
		ListNode* D=new ListNode(7);
		ListNode* E=new ListNode(9);
	//	A->next=B;
		B->next=C;
		C->next=D;
		D->next=E;
		
		ListNode* A1=new ListNode(1);
		ListNode* B1=new ListNode(2);
		ListNode* C1=new ListNode(3);
		ListNode* D1=new ListNode(4);
		ListNode* E1=new ListNode(5);
		A1->next=B1;
		B1->next=C1;
		C1->next=D1;
		D1->next=E1;
		
		ListNode* A2=new ListNode(1);
		ListNode* B2=new ListNode(4);
		ListNode* C2=new ListNode(5);
		ListNode* D2=new ListNode(8);
		ListNode* E2=new ListNode(9);
	//	A2->next=B2;
		B2->next=C2;
		C2->next=D2;
		D2->next=E2;
		
		vector<ListNode*> X;
		X.push_back(A);
		X.push_back(NULL);
		X.push_back(A2);
		ListNode* res=mergeKLists(X);
		for(;res;res=res->next)
			cout<<res->val<<" ";
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
