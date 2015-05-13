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
class MinStack {
private:
    typedef struct node{
        int val;
        node* next;
        node(int x):val(x),next(NULL){}
    }node_t;
    node_t *head,*top_l;
    node_t *min_l;
public:
	MinStack():head(NULL),top_l(NULL),min_l(NULL){}
    void push(int x) {
        node_t *curnode=new node_t(x);
        if(head==NULL)
            top_l=head=curnode;
        else{
            top_l->next=curnode;
            top_l=curnode;
        }
        if(min_l==NULL)
            min_l=new node_t(x);
        else if(min_l->val>=x){
            node_t *minnode=new node_t(x);
            minnode->next=min_l;
            min_l=minnode;
        }
    }
    
    void pop() {
        if(top_l->val==min_l->val){
            node_t *cur=min_l->next;
            free(min_l);
            min_l=cur;
        }
        if(top_l==head){
            free(head);
            head=NULL;
        }
        else{
            for(top_l=head;top_l->next->next;top_l=top_l->next);
            free(top_l->next);
            top_l->next=NULL;
        }
    }

    int top() {
        return top_l->val;
    }

    int getMin() {
        return min_l->val;
    }
    void print(){
    	cout<<top()<<" ~~ "<<getMin()<<"~~"<<endl<<endl;
    //	for(node_t *x=min_l;x;x=x->next)
   	//	cout<<x->val<<" ";
    //	cout<<endl;
	}
};
int main()
{
	MinStack A;
	A.push(4);
	A.push(3);
	A.print();

	A.push(2);
	A.print();

	A.push(0);
	A.print();
	
	A.pop();
	A.print();
	A.pop();
	A.print();
	A.pop();
	A.print();
	
	A.push(2);
	cout<<A.getMin()<<endl;
	cout<<A.top()<<endl<<endl;
	A.push(0);
	cout<<A.getMin()<<endl;
	cout<<A.top()<<endl<<endl;	
	A.pop();
	cout<<A.getMin()<<endl;
	cout<<A.top()<<endl<<endl;
	A.push(3);
	A.push(0);
	cout<<A.getMin()<<endl;
	cout<<A.top()<<endl<<endl;
	A.pop();
	cout<<A.getMin()<<endl;
	cout<<A.top()<<endl<<endl;
	system("pause");
}
