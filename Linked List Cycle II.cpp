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
class Solution {
public:
//通过1的算法可知，用龟兔赛跑的方法，第一个节点以step为1跑，第二个以step为2跑
//当他们能够相遇则说明有环。
//由以上算法可以看出，假设相遇点位S，起始点为A，换的起点为M，起点M到S的距离为K
//假设从S点再走K步将回到S，从M点走K步也是到S点，他们的第一个重合点将是环的起点
    ListNode *detectCycle(ListNode *head) {
        ListNode *S,*A;
    
        if(head==NULL||head->next==NULL)
            return NULL;
        for(S=head->next->next,A=head->next;A!=NULL&&S!=NULL;A=A->next){
            if(A==S)
                break;
            if(S->next)
                S=S->next->next;
            else 
                S=NULL;
        }
        if(A==NULL||S==NULL)
            return NULL;
        for(A=head;A!=S;A=A->next,S=S->next);
        return A;
    }

    void print()
    {
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
