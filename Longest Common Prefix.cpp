#include<iostream>
#include<string>
#include <sstream>
#include<vector>
using namespace std;
class Solution {
public:
    string longestCommonPrefix(vector<string> &strs) {
        int size=strs.size();
        if(size==0)
        	return "";
        string cur=strs[0];
        for(int i=1;i<size;i++)
        	com(cur,strs[i]);
        return cur;
    };
    int com(string &cur1,string cur2)
    {
		string cur;
		for(int i=0;i<cur1.length();i++)
		{
			if(cur1[i]==cur2[i])
				cur+=cur1[i];
			else
				break;
		}
		cur1=cur;
	}
};

int main()
{
	Solution a;
	string e,b,c,d;
	e="abab";
	b="aba";
//	c="abadkkk";
	d="ab";
	vector <string> p;
	
	p.push_back(e);
//	p.push_back(c);
	p.push_back(d);
	p.push_back(b);
	
//	int c=2147483647;
//	cout<<c<<endl;
	cout<<a.longestCommonPrefix(p)<<endl;
	system("pause");
} 
