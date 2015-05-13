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
    int longestConsecutive(vector<int> &num) {
    	if(num.size()==0)
			return 0;
        int res=0,i,j;
		int min_val=num[0];
		int max_val=num[0];
		int flag[65536]={0};
		for(i=0;i<num.size();i++){
			min_val=min(min_val,num[i]);
			max_val=max(max_val,num[i]);
		} 
		for(i=0;i<num.size();i++){
			flag[num[i]-min_val]=1;
		}
		for(i=min_val,j=i;i<=max_val;i++){
			if(flag[i-min_val]==0&&(flag[i-min_val+1]==1)){
				j=++i;
			}
			if(flag[i-min_val]){
				res=max(res,i-j+1);	
			}

		}
//		cout<<min_val<<endl<<max_val<<endl;
		return res;
    }

    void print()
    {
    	vector<int> A;
    	vector<int> B;
    	A.push_back(4);
    	A.push_back(2);
    	A.push_back(5);
    	cout<<longestConsecutive(A)<<endl;
    	A.push_back(3);
    	cout<<longestConsecutive(A)<<endl;
    	A.push_back(6);
    	cout<<longestConsecutive(A)<<endl;
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
