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
    bool isScramble(string s1, string s2) {
        int res=1;
		check(s1,s2,res);
		return res;
    }
    void check(string s1,string s2,int &res){
    	cout<<s1<<" "<<s2<<endl;
    	int len1=s1.length();
    	int len2=s2.length();
    	int i;
    	
		if(s1==s2)
			return;
    	if(len1!=len2||(len1==1&&s1!=s2)){
    		res=0;
    		return;
		}
		if(len1==0)
			return;
		for(i=0;s2[i]!=s1[0];i++);
		if(i<len1&&s2[i]==s1[0]){
			string sub1=s1.substr(1,i);
			string sub2=s2.substr(0,i);
			sort(sub1.begin(),sub1.end());
			sort(sub2.begin(),sub2.end());
			if(sub1==sub2){
				check(s1.substr(1,i),s2.substr(0,i),res);
				check(s1.substr(i+1,len1-i),s2.substr(i+1,len2-i),res);
			}
			else{
				check(s1.substr(1,i),s2.substr(i+1,len2-i),res);
				check(s1.substr(i+1,len1-i),s2.substr(0,i),res);	
			}
			
			
		}
		else
			res=0;
	}
    void print()
    {
		//cout<<isScramble("rgtae","great")<<endl;
		//cout<<isScramble("rgeat","great")<<endl;
		//cout<<isScramble("r","g")<<endl;
		cout<<isScramble("abc","cab")<<endl;
		//cout<<isScramble("sgeat","sreat")<<endl;
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
