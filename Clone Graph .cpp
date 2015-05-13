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
typedef struct UndirectedGraphNode {
    int label;
    vector<UndirectedGraphNode *> neighbors;
    UndirectedGraphNode(int x) : label(x) {};
}UndirectedGraphNode;
class Solution {
public:
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
    	UndirectedGraphNode *res,*A;
    	
		vector<UndirectedGraphNode *> stack;
		vector<UndirectedGraphNode *> init;
		UndirectedGraphNode *cur,*cur_node;
		int flag,count=1,i=0,j,m,pre_size,size;
		

		if(!node)
			return node;
		cur_node=res;
		cout<<node->label<<endl;
		cout<<"  "<<sizeof(node)<<endl;
		cout<<"__"<<node->neighbors[0]->label<<endl;
		cout<<stack.size()<<endl;
		stack.push_back(A);
		cout<<stack.size()<<endl;
		for(i=0;count;i=pre_size){
			count=0;
			pre_size=stack.size();
			cout<<pre_size<<endl;
			for(;i<pre_size;i++){
				cur_node=(UndirectedGraphNode*)malloc(sizeof(UndirectedGraphNode));
				cur_node->label=stack[i]->label;
				cur_node->neighbors=init;
				size=stack[i]->neighbors.size();
				for(j=0;j<size;j++){
					cur=stack[i]->neighbors[j];
					cur_node->neighbors.push_back(cur);
					for(flag=0,m=0;m<pre_size;m++){
						if(stack[m]==cur){
							flag=1;break;
						}
					}
					if(flag==0){
						stack.push_back(cur);
						count++;
					}
				}
			}
			cout<<i<<" "<<stack.size()<<endl;
		}	
		return res;
    }

    void print()
    {
    	UndirectedGraphNode *A,*B,*C,*D;
    	A=(UndirectedGraphNode*)malloc(sizeof(UndirectedGraphNode));
    	B=(UndirectedGraphNode*)malloc(sizeof(UndirectedGraphNode));
    	C=(UndirectedGraphNode*)malloc(sizeof(UndirectedGraphNode));
 //   	A=new UndirectedGraphNode;
 //   	B=new UndirectedGraphNode;
 //   	C=new UndirectedGraphNode;
    	vector<UndirectedGraphNode*> cur; 
    	vector<UndirectedGraphNode*> cur2; 
    	vector<UndirectedGraphNode*> cur3; 
    	
    	A->label=0;
    	B->label=1;
    	C->label=2;
    	//D=(UndirectedGraphNode*)malloc(sizeof(UndirectedGraphNode));
		cur.push_back(B);
		cur.push_back(C);
		cur2.push_back(C);
		cur3.push_back(C);
		
		A->neighbors=cur;
		B->neighbors=cur2;
		C->neighbors=cur3;
	
		cout<<cur[0]->label<<endl;
		cout<<cur[1]->label<<endl;
		cout<<cur2[0]->label<<endl<<endl;
		cout<<((A->neighbors)[0])->label<<endl;
		cout<<A->neighbors[1]->label<<endl;
		cout<<B->neighbors[0]->label<<endl<<endl;
		
		cout<<A->neighbors.size()<<endl;
		cout<<B->neighbors.size()<<endl;
		cout<<C->neighbors.size()<<endl;
		D=cloneGraph(A);
		cout<<D->label<<endl;
		cout<<D->neighbors[0]->label<<endl;
		cout<<D->neighbors[1]->label<<endl;
		cout<<D->neighbors[0]->neighbors[0]->label<<endl;
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
