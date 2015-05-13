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
        vector<int> vec;
        int i,j,size,flag;
        
        if(n==0||n==1)
            return 0;
        vec.push_back(2);
        for(i=3;i<=n;i++){
            size=vec.size();
            for(j=0,flag=0;j<size;j++){
                if(i%vec[j]==0){
                	flag=1;
                	break;
				}
            }
            if(!flag){
            	vec.push_back(i);
			}
        }
        return vec.size();
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
