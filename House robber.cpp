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
    int rob(vector<int> &num) {
    	int *flag=(int*)malloc(sizeof(int)*num.size());
    	for(int i=0;i<num.size();i++)
    		flag[i]=-1;
        return check(num,num.size(),flag);
    }
    int check(vector<int> &num,int i,int *flag){
    	if(i==0)
    		return 0;
    	if(i==1)
    		flag[i-1]=num[i-1];
    	if(flag[i-1]<0)		
			flag[i-1]=max(num[i-1]+check(num,i-2,flag),check(num,i-1,flag));
		return flag[i-1];
	} 
    void print()
    {
    	vector<int> A;
    //	A.push_back(1);
    	cout<<rob(A)<<endl;
    	A.push_back(2);
    	A.push_back(3);
    	A.push_back(4);
    	cout<<rob(A)<<endl;

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
