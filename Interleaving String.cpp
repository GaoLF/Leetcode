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
    bool isInterleave(string s1, string s2, string s3) {
        int res=0;
		if((s1.length()+s2.length())!=s3.length())
			return res;
		check(0,0,0,s1,s2,s3,res);
        return res;
    }
    void check(int s1_i,int s2_i,int s3_i,string &s1,string& s2,string& s3,int &res){
    	int len1=s1.length();
    	int len2=s2.length();
    	int len3=s3.length();
    	//cout<<s1_i<<" "<<s2_i<<" "<<s3_i<<endl;
    	//cout<<s1[s1_i]<<" "<<s2[s2_i]<<" "<<s3[s3_i]<<endl;
    	if(s3_i==len3){
    		res=1;
    		return;
		}
    	if(s1_i==len1||s1[s1_i]!=s3[s3_i]){
    	//	cout<<1<<endl;
    		if(s2_i<len2&&s2[s2_i]==s3[s3_i])
    			check(s1_i,s2_i+1,s3_i+1,s1,s2,s3,res);
    		//return;
    		
		}
		else if(s2_i==len2||s2[s2_i]!=s3[s3_i]){
		//	cout<<2<<endl;
			if(s1_i<len1&&s1[s1_i]==s3[s3_i])
				check(s1_i+1,s2_i,s3_i+1,s1,s2,s3,res);
			
    		//return;
		}
		else if(s1[s1_i]==s2[s2_i]&&s1[s1_i]==s3[s3_i]){
			int a,b,c;
			for(a=1;a+s1_i<len1&&s1[a+s1_i]==s1[s1_i];a++);
			for(b=1;b+s2_i<len2&&s2[b+s2_i]==s2[s2_i];b++);
			for(c=1;c+s3_i<len3&&s3[c+s3_i]==s3[s3_i];c++);
			//check(s1_i+1,s2_i,s3_i+1,s1,s2,s3,res);
			//if(s1_i+1<len1&&s2_i+1<len2&&s1[s1_i+1]==s1[s1_i]&&s2[s2_i+1]==s2[s2_i]);
			//else
			//	check(s1_i,s2_i+1,s3_i+1,s1,s2,s3,res);
			if(a+b==c)
				check(s1_i+a,s2_i+b,s3_i+c,s1,s2,s3,res);
			else{
			    if(a<=c)
			 		check(s1_i+a,s2_i+c-a,s3_i+c,s1,s2,s3,res);
				if(b<=c)
					check(s1_i+c-b,s2_i+b,s3_i+c,s1,s2,s3,res);
			}
			
		}
	}

    void print()
    {
		string s1,s2,s3,s4;
		s1="cbcccbabbccbbcccbbbcabbbabcababbbbbbaccaccbabbaacbaabbbc";
		s2="abcbbcaababccacbaaaccbabaabbaaabcbababbcccbbabbbcbbb";
		s3="abcbcccbacbbbbccbcbcacacbbbbacabbbabbcacbcaabcbaaacbcbbbabbbaacacbbaaaabccbcbaabbbaaabbcccbcbabababbbcbbbcbb";
		//s4="aadbbbaccc";
		cout<<isInterleave(s1,s2,s3)<<endl;
		cout<<isInterleave(s1,s2,s4)<<endl;//"cbcccbabbccbbcccbbbcabbbabcababbbbbbaccaccbabbaacbaabbbc", "abcbbcaababccacbaaaccbabaabbaaabcbababbcccbbabbbcbbb", "abcbcccbacbbbbccbcbcacacbbbbacabbbabbcacbcaabcbaaacbcbbbabbbaacacbbaaaabccbcbaabbbaaabbcccbcbabababbbcbbbcbb"
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
