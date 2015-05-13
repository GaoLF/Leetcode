#include<iostream>
#include<string>
#include<vector>
#include <cctype>
#include<algorithm>
#include<math.h>
using namespace std ;
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
    ListNode *deleteDuplicates(ListNode *head) {   
		if(!head||!(head->next))
    		return head; 
    	int flag=0;
		int headflag=0; 
    	ListNode *curnode,*prenode=head;
    	for(curnode=prenode;curnode;curnode=curnode->next){
    		for(flag=0;curnode->next&&(curnode->val==curnode->next->val);curnode=curnode->next){
    			flag=1;
			}
			if(!flag){
				if(!headflag){
					head=curnode;
					prenode=head;
					headflag=1;
				}
				else{
					prenode->next=curnode;
					prenode=curnode;
				}
			}
			else if(!(curnode->next))
				prenode->next=NULL;
		}
		if(flag&&!headflag)
			head=NULL;
		return head;
    }

    void print()
    {
		ListNode A(1),B(2),C(3),D(4),E(5),*F;
		A.next=&B;
		B.next=&C;
		C.next=&D;
		D.next=&E;
		F=deleteDuplicates(&A);
		for(;F;F=F->next){
			cout<<F->val<<endl;
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
