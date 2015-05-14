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
    int evalRPN(vector<string>& tokens) {
        int res;
		int i,j,temp1,temp2;
		int size=tokens.size();
		stack<int> nums;
		if(tokens.empty())
			return 0;
		for(i=0;i<size;i++){
			if(tokens[i]=="+"){
				temp1=nums.top();
				nums.pop();
				temp2=nums.top();
				nums.pop();
				nums.push(temp1+temp2);
			}
			else if(tokens[i]=="-"){
				temp1=nums.top();
				nums.pop();
				temp2=nums.top();
				nums.pop();
				nums.push(temp2-temp1);
			}
			else if(tokens[i]=="*"){
				temp1=nums.top();
				nums.pop();
				temp2=nums.top();
				nums.pop();
				nums.push(temp1*temp2);
			}
			else if(tokens[i]=="/"){
				temp1=nums.top();
				nums.pop();
				temp2=nums.top();
				nums.pop();
				nums.push(temp2/temp1);
			}
			else
				nums.push(atoi(tokens[i].c_str()));
		} 
		return nums.top();
    }
    void print()
    {
		vector<string> A;
		A.push_back("4");
		A.push_back("13");
		A.push_back("5");
		A.push_back("/");
		A.push_back("+");
		cout<<evalRPN(A)<<endl;
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
