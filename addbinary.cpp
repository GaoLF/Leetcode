#include<iostream>
#include<string>
#include<vector>
#include <cctype>
#include<algorithm>
using namespace std ;
class Solution {
public:
	////////////////////////
	////////////////////////****************"^"是异或操作，如果用异或操作会容易很多！！！！！******* 
	///////////////////////可以将短的string前边填充上"0000”来简化操作 ！！！！！！！ 
    string addBinary(string a, string b) {
        string res="";
        string cur="";
        int i,intera,interb,flag;
        for(i=min(a.length(),b.length()),intera=a.length()-1,interb=b.length()-1,flag=0;i>0;i--,intera--,interb--)
        {
            int cursum=0;
            if((a[intera]=='0'&&b[interb]=='1')||(a[intera]=='1'&&b[interb]=='0'))
            {
                if(flag)
					res.insert(0,"0");
//                    res[0]='0';
                else
                    res.insert(0,"1");
            }
            else 
            {
                if(flag)              
					res.insert(0,"1");
//                    res[0]='1';
                else
                    res.insert(0,"0");
                if(a[intera]=='1')
                    flag=1;
                else
                    flag=0;
            }
        }   
        if(a.length()==b.length())
        {
            if(flag)
                res.insert(0,"1");
            return res;
        }
        if(a.length()>b.length())
            for(int p=0;p<a.length()-b.length();p++)
                cur+=a[p];
        else
            for(int p=0;p<b.length()-a.length();p++)
                cur+=b[p];
        for(i=cur.length()-1;i>=0;i--)
        {
            if(cur[i]=='0')
            {
                if(flag)
                    res.insert(0,"1");
                else
                    res.insert(0,"0");
                flag=0;
            }       
            else
            {
                if(flag)
                    res.insert(0,"0");
                else
                    res.insert(0,"1");
            }
        }
        if(flag)
            res.insert(0,"1");
        return res;
            
    }   
	void print()
	{	
		string a="1";
		string b="11";
		cout<<addBinary(a,b)<<endl;
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
