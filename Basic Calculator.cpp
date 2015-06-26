#include<iostream>
#include<string>
#include<vector>
#include <cctype>
#include<algorithm>
#include<math.h>
#include<stack>
#include<list>
using namespace std ;
typedef struct ListNode{
	int val;
	ListNode * next;
} ListNode;
class Solution {
public:
    int calculate(string s) {
        // the given expression is always valid!!!
        // only + and - !!!
        // every + and - can be flipped base on it's depth in ().
        stack<int> signs;
        int sign = 1;
        int num = 0;
        int ans = 0;

        // always transform s into ( s )
        signs.push(1);

        for (auto c : s) {
            if (c >= '0' && c <= '9') {
                num = 10 * num + c - '0';
            } else if (c == '+' || c == '-') {
                ans = ans + signs.top() * sign * num;
                num = 0;
                sign = (c == '+' ? 1 : -1);
            } else if (c == '(') {
                signs.push(sign * signs.top());
                sign = 1;
            } else if (c == ')') {
                ans = ans + signs.top() * sign * num;
                num = 0;
                signs.pop();
                sign = 1;
            }
        }

        if (num) {
            ans = ans + signs.top() * sign * num;
        }

        return ans;
    }

    void print()
    {
    	cout<<calculate("")<<endl;
		cout<<calculate("(8+4-(1)+8-10)")<<endl;
		cout<<calculate("(8+2-6+(8+4-(1)+8-10))")<<endl;
		cout<<calculate("2-4-(8+2-6+(8+4-(1)+8-10))")<<endl;
		cout<<calculate("2-1 + 2 ")<<endl;
		cout<<calculate("(1+(4+5+2)-3)+(6+8)")<<endl;
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
