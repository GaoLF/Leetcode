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
//	static vector<int> count;
//	static vector<int> sushu; 
    int countPrimes(int n) {
		int size=15000000;
		int res=0;
		int i,j;
		bool flag[size];
		
		for(i=0;i<size;i++)
			if(i%2)
				flag[i]=1;
			else
				flag[i]=0;
		for(i=2;i<sqrt(n);i+=1){
			if(flag[i]){
				for(j=i+i;j<=n;j+=i)
					flag[j]=0;
			}
		}
		flag[2]=1;
		for(i=2;i<=n;i++){
			if(flag[i]){
	//			cout<<i<<" ";
				res++;
			}
		}
	//	cout<<endl;
		return res;
    }
    void print()
    {
    	cout<<countPrimes(3)<<endl;
    	cout<<countPrimes(10)<<endl;
    	cout<<countPrimes(499979)<<endl;
    	

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
