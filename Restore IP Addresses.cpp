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
    vector<string> restoreIpAddresses(string s) {
    	//unordered_map<int,string> map;
        vector<string> res;
        int temp=atoi(s.c_str());
        
		check(s,4,"",res);
		return res;
    }
    void check(string s,int num,string foo,vector<string> &res){
    	int length=s.length();
    	
    	if(length<num||length/num>3)
    		return;
    	if(num==1){
    		if(s[0]=='0'&&s!="0")
    			return;
    		int temp=atoi(s.c_str());
    		if(temp<=255)
    			res.push_back(foo+s);
    		return;
		}
				
		for(int i=1;i<=3&&i<length;i++){
			string sub1=s.substr(0,i);
			string sub2=s.substr(i,length-1);
			int temp=atoi(sub1.c_str());
			if(temp<=255)
				check(sub2,num-1,foo+sub1+".",res);
			if(sub1=="0")
				break;
		}
	}

    void print()
    {
    	vector<string> res;
		res=restoreIpAddresses("25525511135");
		for(int i=0;i<res.size();i++)
			cout<<res[i]<<endl;
		cout<<endl;
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
