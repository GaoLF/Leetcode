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
    	int *flag1=(int*)malloc(sizeof(int)*num.size());
    	int *flag2=(int*)malloc(sizeof(int)*num.size());
    	if(!num.size())
    		return 0;
    	if(num.size()==1)
    	    return num[0];
    	for(int i=0;i<num.size();i++){
    		flag1[i]=-1;
    		flag2[i]=-1;
		}
    		
        int res1=check(num,num.size()-1,flag1);
        num[0]=0;
        int res2=check(num,num.size(),flag2);
        return max(res1,res2);
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
	void print(){
		int A[]={1,2,3,4,5,6,7,8,9};
		vector<int> res(A,A+9);
		cout<<rob(res)<<endl;
		
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
