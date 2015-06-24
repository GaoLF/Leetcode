#include<iostream>
#include<string>
#include<vector>
#include <cctype>
#include<algorithm>
#include<math.h>
#include<stack>
using namespace std ;
typedef struct ListNode{
	int val;
	ListNode * next;
} ListNode;
class Solution {
public:
int largestRectangleArea(vector<int> &height) {
        int n=height.size();
        if(n==0) return 0;
        if(n==1) return height[0];

        height.push_back(0);
        n++;

        int ans=0;
        stack<int> s;

        int i=0,j=0,h=0;
        while(i<n){
            if(s.empty() || height[i]>height[s.top()]) s.push(i++);
            else{
                h=height[s.top()];
                s.pop();
                j= s.empty() ? -1:s.top();
                ans=max(ans,h*(i-j-1));
            }
        }
        return ans;
    }

    void print()
    {
		int A[]={2,3,4,5};
		//int A[]={2,2,2,1,1,1,1,1,1,1};
		vector<int> B(A,A+1);
		vector<int> C(A,A+2);
		vector<int> D(A,A+4);
		//cout<<largestRectangleArea(B)<<endl;
		//cout<<largestRectangleArea(C)<<endl;
		cout<<largestRectangleArea(D)<<endl;
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
