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
class List{
	private:
	ListNode *head,*end;
	int list_size;
	public:
	List():list_size(0),head(NULL),end(NULL){}
	void push(int x){
		ListNode *node=new ListNode(x);
		if(!head){	
			end=head=node;
		}
		else{
			end->next=node;
			end=node;
		}
		list_size++;
	}
	int pop(){
		ListNode* cur=head;
		int res=cur->val;
		if(list_size){
			head=head->next;
			list_size--;
		}
		return res;
	}
	int size(){
		return list_size;
	}
	bool isempty(){
		if(list_size)
			return false;
		else
			return true;
	}
};
class Stack {
public:
	private:
	List A,B;
	//int size;
    // Push element x onto stack.
    public:
    void push(int x) {
        if( ! (A.isempty()) ) 
        	A.push(x);
        else
        	B.push(x);
    }

    // Removes the element on top of the stack.
    void pop() {
        if(A.isempty()){
        	int size=B.size();
        	for(int i=0;i+1<size;i++)
        		A.push(B.pop());
        	B.pop();
		}
		else{
			int size=A.size();
			for(int i=0;i+1<size;i++)
				B.push(A.pop());
			A.pop();
		}
    }

    // Get the top element.
    int top() {
    	int res;
        if(A.isempty()){
        	int size=B.size();
        	for(int i=0;i<size;i++){
        		res=B.pop();
        		A.push(res);
			}
		}
		else{
			int size=A.size();
			for(int i=0;i<size;i++){
				res=A.pop();
				B.push(res);
			}
		}
		return res;
    }

    // Return whether the stack is empty.
    bool empty() {
        if(A.isempty()&&B.isempty())
        	return true;
        else
        	return false;
    }
    void print()
    {
    	cout<<A.isempty()<<"~"<<B.isempty()<<endl;
		cout<<top()<<"!!"<<top()<<endl;
	}
};
int main()
{
	Stack A;
	A.push(1);
	A.push(2);
	cout<<A.top()<<endl;
	cout<<A.empty()<<endl;
	A.pop();
	cout<<A.top()<<endl;
	A.pop();
//	A.print();
	cout<<A.empty()<<endl;
	system("pause");
}
