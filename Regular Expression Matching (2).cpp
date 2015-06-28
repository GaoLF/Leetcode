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
    bool isMatch(string s,string p) {
    	int i,j;
    	int len1=s.length();
    	int len2=p.length();
    	char temp;
    	for(i=0,j=0,temp=p[0];j<len2;i++,temp=p[j]){
    		
    			
    		if(p[j+1]!='*')
    			j++;
    		else if(((j+2)<=len2)&&isMatch(s.substr(i,len1-i),p.substr(j+2,len2-j-2)))
    			return true;
    			
    		if((i>=len1)||((temp!='.')&&(s[i]!=temp)))
    			return false;
		}
		return !(i<len1);

		
		/*
        for( char c = *p; c != 0; ++s, c = *p ) {
            if( *(p+1) != '*' )
                p++;
            else if( isMatch( s, p+2 ) )
                return true;
            if( (*s==0) || ((c!='.') && (c!=*s)) )
                return false;
        }
        return *s == 0;*/
    }

    void print()
    {
		cout<<isMatch("aab","a*b")<<endl;
		cout<<isMatch("aa","aa")<<endl;
		cout<<isMatch("aaa","aa")<<endl;
		cout<<isMatch("aa", "a*")<<endl;
		cout<<isMatch("aa", ".*")<<endl;
		cout<<isMatch("ab", ".*")<<endl;
		cout<<isMatch("abbcacbbbbbabcbaca", "a*a*.*a*.*a*.b*a*")<<endl;
		
		cout<<isMatch("abbcacbbbbbabcbaca", "a*a*.*a*.*a*.b*a*")<<endl;
		cout<<isMatch("bbab", "b*a*")<<endl;
		cout<<isMatch("aabcbcbcaccbcaabc", ".*a*aa*.*b*.")<<endl;
		
		cout<<isMatch("abbabaaaaaaacaa", "a*.*b.a.*c*b*a*c*")<<endl;
		cout<<isMatch("cabbbbcbcacbabc", ".*b.*.ab*.*b*a*c")<<endl;
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
