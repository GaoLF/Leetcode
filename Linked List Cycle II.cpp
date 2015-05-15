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
//ͨ��1���㷨��֪���ù������ܵķ�������һ���ڵ���stepΪ1�ܣ��ڶ�����stepΪ2��
//�������ܹ�������˵���л���
//�������㷨���Կ���������������λS����ʼ��ΪA���������ΪM�����M��S�ľ���ΪK
//�����S������K�����ص�S����M����K��Ҳ�ǵ�S�㣬���ǵĵ�һ���غϵ㽫�ǻ������
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
