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
    int numDecodings(string s) {
		int *flag;
		if(s.length()==0)
			return 0;
		flag=(int*)malloc((s.length()+1)*sizeof(int));
		for(int i=0;i<=s.length();i++)
			flag[i]=-1;
		return decode(s,0,flag);
    }
	int decode(string s,int i,int *flag){
		int size=s.length();
		if(s[i]=='0')
			return 0;
		if(i==size)
			return 1;
		if((i+1)==size)
			return 1;
		if(flag[i]!=-1)
			return flag[i];
		if(s[i]=='1'){
			if(s[i+1]=='0')
				flag[i]=decode(s,i+2,flag);
			else
				flag[i]=decode(s,i+1,flag)+decode(s,i+2,flag);
		}
		else if(s[i]=='2'){
			if((s[i+1]>='1')&&(s[i+1]<='6'))
				flag[i]=decode(s,i+1,flag)+decode(s,i+2,flag);
			else
				flag[i]=decode(s,i+2,flag);
		}
		else{
			flag[i]=decode(s,i+1,flag);
		}
		
		return flag[i];		
	}
    void print()
    {
    	cout<<numDecodings("00")<<endl;
		cout<<numDecodings("0")<<endl;
		cout<<numDecodings("12")<<endl;
		cout<<numDecodings("123")<<endl;
		cout<<numDecodings("100")<<endl;
		cout<<numDecodings("123456")<<endl;
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
