#include<iostream>
#include<string>
#include<vector>
#include <sstream>
using namespace std;
class Solution {
public:
    int romanToInt(string s) {
        vector<int> num;
        int sum=0;
        for(int i=0;i<s.length();i++)
        	num.push_back(r2n(s[i]));
        if(s.length()==1)
			return num[0];
        for(int i=0;i<s.length()-1;i++)
        {
			if(num[i]<num[i+1])
				sum-=num[i];
			else 
				sum+=num[i];
		}
		sum+=num[s.length()-1];
		return sum;
    }
    int r2n(char x)
    {
		switch (x){
			case 'I': return 1;
			case 'V': return 5;
			case 'X': return 10;
			case 'L': return 50;
			case 'C': return 100;
			case 'D': return 500;
			case 'M': return 1000;
			default: return 0;
		}
	}
};
int main()
{
	Solution a;
	string b="IVX";
	int c=2147483647;
	cout<<a.romanToInt("I")<<endl;
	//cout<<a.reverse(-2147480092)<<endl;
	system("pause");
} 
