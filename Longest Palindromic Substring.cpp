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

    string longestPalindrome(string s) {
        int i,j,cur,count=0;
        int start=0,end=0;
        string sub,res;
		int size=s.length();

		if(size==0||size==1)
			return s;
		for(i=0,j=size-1;i<j;i++){
			if(i>start){
				for(cur=size-1;cur>end;cur--){
					if(i>start&&cur<end)
						break;
					if(s[cur]==s[i]){
						sub=s.substr(i,cur-i+1);
						if(check(sub)&&(sub.length()>count)){
							count=sub.length();
							res=sub;
							start=i;
							end=cur;
							j=size-count;
							break;
						}
					}
				}
			}
			else{
				for(cur=size-1;cur>i;cur--){
					if(i>start&&cur<end)
						break;
					if(s[cur]==s[i]){
						sub=s.substr(i,cur-i+1);					
						if(check(sub)&&(sub.length()>count)){
							count=sub.length();
							res=sub;
							start=i;
							end=cur;
							j=size-count;
							break;
						}
					}
				}
			}
		}
		return res;
    }
	int check(string A){
		int size=A.length();
		int i;
		for(i=0;i<(size/2);i++){
			if(A[i]!=A[size-i-1])
				return 0;
		}
		return 1;
	}
    void print()
    {
		string A="aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaabcaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa";
		string res=longestPalindrome(A);
		
		cout<<res<<endl;
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
