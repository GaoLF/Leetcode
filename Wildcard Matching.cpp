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
 bool isMatch(string A,  string B) {
 		int i;
 		int len1=A.length();
 		int len2=B.length();
 		char *s=new char[len1];
		char *p=new char[len2];
		for(i=0;i<len1;i++)
			s[i]=A[i];
		s[i]='\0';
		for(i=0;i<len2;i++)
			p[i]=B[i];
		p[i]='\0';

        char* star=NULL;
        char* ss=s;
        while (*s){
            //advancing both pointers when (both characters match) or ('?' found in pattern)
            //note that *p will not advance beyond its length 
            if ((*p=='?')||(*p==*s)){s++;p++;continue;} 

            // * found in pattern, track index of *, only advancing pattern pointer 
            if (*p=='*'){star=p++; ss=s;continue;} 

            //current characters didn't match, last pattern pointer was *, current pattern pointer is not *
            //only advancing pattern pointer
            if (star){ p = star+1; s=++ss;continue;} 

           //current pattern pointer is not star, last patter pointer was not *
           //characters do not match
            return false;
        }

       //check for remaining characters in pattern
        while (*p=='*'){p++;}

        return !*p;  
    }
    void print()
    {
		cout<<isMatch("aa","a")<<endl;
		cout<<isMatch("aa","aa")<<endl;
		cout<<isMatch("aaa","aa")<<endl;
		cout<<isMatch("aa", "*")<<endl;
		cout<<isMatch("aa", "a*")<<endl;
		cout<<isMatch("ab", "?*")<<endl;
		cout<<isMatch("aab", "c*a*b")<<endl;	
		cout<<isMatch("babaabbbbbaaaaabbaababbaaaaaaabbaabaabbbabbaabbbbb", "*ba**bbbb")<<endl;
		cout<<isMatch("bbaaababbaaababababbb", "*a*****bb")<<endl;
		cout<<isMatch("baabaaabbaaaaabababbbbaabbaaabaababbababbaababbaabbb", "*bbb***a*baa*bab**bb")<<endl;

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
