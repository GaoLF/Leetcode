#include<iostream>
#include<string>
#include<vector>
#include <cctype>
#include<algorithm>
#include<math.h>
#include<unordered_map>
using namespace std ;
typedef struct ListNode{
	int val;
	ListNode * next;
} ListNode;
 struct RandomListNode {
     int label;
     RandomListNode *next, *random;
     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 };
class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        unordered_map<RandomListNode*,RandomListNode*> map;
        RandomListNode *iter,*node2cp,*node,*noderd;
        RandomListNode *res=new RandomListNode(0);
    	unordered_map<RandomListNode*,RandomListNode*>::iterator mapiter;
    	
        if(head==NULL)
        	return NULL;
        res->label=head->label;
        for(iter=head,node2cp=res;iter;iter=iter->next){
        	if(iter!=head){
        		mapiter=map.find(iter);
       			if(mapiter==map.end()){
       				node=new RandomListNode(iter->label);
					node2cp->next=node;
					map.insert(make_pair(iter,node));	
				}
				else{
					node2cp->next=mapiter->second;
					//node=node->next;
				}
				node2cp=node2cp->next;
			}
			//for(noderd=iter->random;noderd;noderd=noderd->random)
			if(iter->random){
				mapiter=map.find(iter->random);
				if(mapiter==map.end()){
					node=new RandomListNode(iter->random->label);
					node2cp->random=node;
					map.insert(make_pair(iter->random,node));
				}
				else
					node2cp->random=mapiter->second;
			}
		}

        return res;
    }

    void print()
    {
		RandomListNode* A=new RandomListNode(1); 
		RandomListNode* B=new RandomListNode(2);
		RandomListNode* C=new RandomListNode(3);
		RandomListNode* D=new RandomListNode(4);
		RandomListNode* E=new RandomListNode(5);
		A->next=B;
		A->random=C;
		B->next=C;
		B->random=A;
		C->next=D;
		C->random=E;
		RandomListNode *res=copyRandomList(A);
		cout<<res->random->label<<endl;
		cout<<res->next->label<<endl;
		cout<<res->random->next->label<<endl;
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
