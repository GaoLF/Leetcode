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
    void rotate(int nums[], int n, int k) {
        int cur1,cur2,i,j,times;
        int flag[65536]={0};
        for(j=0;j<k;j++){
            if(flag[j])
                continue;
            cur2=nums[j];
            for(i=(k+j)%n;i;i=(i+k)%n){
                if(flag[i])
                    break;
                if(i<k)
                    flag[i]=1;
                cur1=nums[i];
                nums[i]=cur2;
                cur2=cur1;
                cout<<"i:"<<i<<"->j:"<<j<<endl;
            }   
            nums[j]=cur2;
        }
    }
    void print()
    {
        int A[7]={1,2,3,4,5,6,7};
        int n=6;
        int k=2;
        rotate(A,n,k);
        for(int i=0;i<n;i++)
            cout<<A[i]<<endl; 
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
