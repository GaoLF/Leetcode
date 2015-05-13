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
    int longestValidParentheses(string s) {
		stack<char> X;
		int res=check(s,0,X); 
    	int size=s.length();
    	char cur;
    	
		return min(check(b,0,0,X),check(s,0,X));
		
		 
    }
    int check(string &s, int start,int end, stack<char>& X){
    	while(X.size())
    		X.pop();
    	int i,count;
		for(i=start,count=0;i<s.length();i++){
			if(s[i]=='('){
				X.push('(');
			}
			if(s[i]==')'){
				if(X.empty())
					return max(check(s,i+1,X),count);
				else{
					count+=2;
					X.pop();
				}
			}
		}
		return count;
	}

    void print()
    {
		cout<<longestValidParentheses("(()()))((()))))))))")<<endl;
		cout<<longestValidParentheses(")()())")<<endl;
		cout<<longestValidParentheses("))))())()()(()")<<endl;
		cout<<longestValidParentheses("()(())")<<endl;
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
