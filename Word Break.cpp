#include<iostream>
#include<string>
#include<vector>
#include <cctype>
#include<algorithm>
#include<math.h>
#include<unordered_set>
using namespace std ;
typedef struct ListNode{
	int val;
	ListNode * next;
} ListNode;
class Solution {
public:
    bool wordBreak(string s, unordered_set<string>& wordDict) {
		bool res=0;
		unordered_set<int> set;
		check(s,wordDict,res,set);
		return res;
    }
    void check(string s, unordered_set<string>& dict, bool &res,unordered_set<int>& set){
    //	cout<<s<<s.length()<<endl;
    	int size=s.length();
    	int i;
    	if(set.find(size)!=set.end())
    		return;
    	string temp;
		if(size==0)
    		res=1;
    	for(i=1;i<=size;i++){
    		temp=s.substr(0,i);
    		if(dict.find(temp)!=dict.end())
    			check(s.substr(i,size-i),dict,res,set);
		}
		set.insert(size);
	}

    void print()
    {
		unordered_set<string> dict;
		dict.insert("leet");
		dict.insert("code");
		cout<<wordBreak("leetccodecodecode",dict)<<endl;
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
