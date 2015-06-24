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
    int maxProfit(vector<int>& prices) {
        int i,size=prices.size();
        int res=0,left=0,right=0;
        for(i=1;i<size;i++){
        	if(prices[i]>prices[i-1]){
        		left=compute(prices,0,i);
        		right=compute(prices,i+1,size-1);
        		res=max(res,left+right);
        		cout<<i<<": "<<left<<" "<<right<<endl;
			}
			
		}
		return res;
    }
    int compute(vector<int>& p,int begin,int end){
    	if(begin>=end)
    		return 0;
    	int i,maxvalue=p[end],res=0;
    	for(i=end;i>=begin;i--){
    		if(p[i]>maxvalue)
    			maxvalue=p[i];
    		else
    			res=max(maxvalue-p[i],res);
		}
		return res;
	}

    void print()
    {
		//int A[]={3,3,5,0,0,3,1,4};
		int A[]={1,2};
		vector<int> B(A,A+2);
		cout<<maxProfit(B)<<endl;
		
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
