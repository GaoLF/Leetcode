#include<iostream>
#include<string>
#include <sstream>
using namespace std;

class Solution {
public:
    string countAndSay(int n) {
        string result="11"; 
        if(n==1)
			return "1";
        for(int i=1;i<=n-2;i++)
        {
			string cur="";
			int flag=1;
			int size=result.length();
			for(int j=1;j<size;j++)
				if(result[j]==result[j-1])
					flag+=1;
				else
				{
					cur=cur+int2str(flag)+result[j-1];
					flag=1;
				}				
			result=cur+int2str(flag)+result[size-1];
		}
		return result;
    }
    string int2str(int &i) 
	{
    	string s;
   	    stringstream ss(s);
    	ss << i;
  		return ss.str();
	}
};

int main()
{
	Solution a;
	string b="";
	b+="a";
	cout<<a.countAndSay(1)<<endl;
	cout<<a.countAndSay(2)<<endl;
	cout<<a.countAndSay(3)<<endl;
	cout<<a.countAndSay(4)<<endl;
//	cout<<std::to_string(213)<<endl;
	system("pause");
} 
