#include<iostream>
#include<string>
#include<vector>
#include <cctype>
#include<algorithm>
using namespace std ;

class MinStack {
public:
    
    struct stack{
		int val;
		stack* next;
	};
	stack *head,*tail;
    MinStack()
    {
		head=(stack*)malloc(sizeof(stack));
		head->next=NULL;
		tail=head;
	}
	void push(int x) {
		stack *cur;
		cur=(stack *)malloc(sizeof(stack));
		cur->next=NULL;
		cur->val=x;
		tail->next=cur;
		tail=cur;
    }
    void pop() {
		stack *cur;
		for(cur=head;cur->next->next;cur=cur->next);
		tail=cur;
		cur->next=NULL;
//		free(cur->next);
    }
    int top() {
		return tail->val;
    }

    int getMin() {
		int res=head->next->val;
		for(stack *cur=head->next;cur;cur=cur->next)
			res=min(res,cur->val);
		return res;
    }
    void print()
    {
		push(-2);
		push(0);
		push(-1);
		cout<<getMin()<<endl;
		cout<<top()<<endl;
		pop();
		cout<<getMin()<<endl;
	}
};
/*
class MinStack {
public:
    
    
	int *head,*tail;
	int size;
    MinStack()
    {
//		head=(int*)malloc(sizeof(int));
//		tail=head+1;
//		tail=(int*)malloc(sizeof(int));
		head=(int*)malloc(sizeof(int)); 
		size=0;
	}
	void push(int x) {
//		int* cur=head+size;
//		cur=(int*)molloc(sizeof(int));
//		*cur=x;
		size++;
		head=(int*)realloc(head,size*sizeof(int));
		*(head+size-1)=x;

	}
    void pop() {
		free(head+size-1);
		size--;
    }
    int top() {
		return *(head+size-1);
    }

    int getMin() {
		int res=*head;
		for(int i=0;i<size;i++)
//			res=min(res,*(head+i));
			if(res>*(head+i))
				res=*(head+i);
		return res;
    }
    void print()
    {
		push(-2);
		push(0);
		push(-1);
		for(int i=0;i<size;i++)
			cout<<*(head+i)<<"~";
		cout<<endl<<getMin()<<endl;
		cout<<top()<<endl;
		pop();
		cout<<getMin()<<endl;
	}
};
*/
int main()
{
	MinStack test;
//	cout<<test.Low("A man, a plan, a canal: Panama")<<endl;
	test.print();
//	cout<<atoi("2147483648")<<endl;
	system("pause");
}
