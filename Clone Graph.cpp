#include<iostream>
#include<string>
#include<vector>
#include <cctype>
#include<algorithm>
#include<math.h>
#include<unordered_map>
#include<stack>
using namespace std ;
typedef struct ListNode{
	int val;
	ListNode * next;
} ListNode;
struct UndirectedGraphNode {
     int label;
     vector<UndirectedGraphNode *> neighbors;
     UndirectedGraphNode(int x) : label(x) {};
};
class Solution {
public:
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        unordered_map<UndirectedGraphNode*,UndirectedGraphNode*> map;
        unordered_map<UndirectedGraphNode*,UndirectedGraphNode*>::iterator iter;
        //vector<UndirectedGraphNode *> iter;
        stack<UndirectedGraphNode*> stack;
        UndirectedGraphNode *temp,*newnode,*curnode;
        int i,size;
        temp=node;
        if(!node)
        	return node;
        UndirectedGraphNode *head=new UndirectedGraphNode(node->label);
        curnode=head;
        map.insert(make_pair(node,head));
        while(1){
        	for(size=temp->neighbors.size(),i=0;i<size;i++){
        		UndirectedGraphNode* tempnode=temp->neighbors[i];
        		iter=map.find(tempnode);
        		if(iter==map.end()){
        			newnode=new UndirectedGraphNode(tempnode->label);
        			curnode->neighbors.push_back(newnode);
					map.insert(make_pair(tempnode,newnode));	
					stack.push(tempnode);
				}
				else{
					curnode->neighbors.push_back(iter->second);
				}
			}
			if(stack.empty())
				return head;
			temp=stack.top();
			stack.pop();
			iter=map.find(temp);
			curnode=iter->second;
		}
		
		return head;
    }
    void print()
    {
    	UndirectedGraphNode* A=new UndirectedGraphNode(0);
    	UndirectedGraphNode* B=new UndirectedGraphNode(1);
    	UndirectedGraphNode* C=new UndirectedGraphNode(2);
    	UndirectedGraphNode* D;
    //	UndirectedGraphNode* D=new UndirectedGraphNode(4);
    	vector<UndirectedGraphNode*> X1;
    	X1.push_back(A);
		X1.push_back(A);
		A->neighbors=X1;
		X1.clear();
		X1.push_back(B);
		B->neighbors=X1;
		X1.clear();
		X1.push_back(C);
		C->neighbors=X1;
		D=cloneGraph(A);
		cout<<D->neighbors.size()<<endl;
		cout<<D->neighbors[0]->neighbors.size()<<endl;
		cout<<D->neighbors[1]->neighbors.size()<<endl;
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
