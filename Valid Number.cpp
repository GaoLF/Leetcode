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
    bool isNumber(string s) {
        int i,j,len=s.length();
		for(i=0;i<len&&s[i]==' ';i++);
		for(j=len-1;j>=0&&s[j]==' ';j--);
		if(j-i<0)
			return 0;
		if(s[i]=='-'||s[i]=='+')
			i++;
		s=s.substr(i,j-i+1);
		int eflag=0,point=0;
		len=s.length();
		for(i=0;i<len;i++){
			//if(s[0]=='-');
			if(isdigit(s[i]));
			else if(s[i]=='.'&&((i>0)||((i+1<len)))){
				point++;
				if(point>1)
					return 0;
			}
			else if(s[i]=='e'&&(i>0)&&((i+1<len))){
				eflag++;
				if(eflag>1)
					return 0;
				if(i+2==len&&(s[i+1]=='.'||s[i+1]=='-'||s[i+1]=='+'))
					return 0;
				if(i==1&&s[i-1]=='.')
					return 0;
				if(s[i+1]=='+'||s[i+1]=='-')
					i++;
				point=0;
			}			
			else
				return 0;	
		}
		return 1;
    }
	bool isdigit(char x){
		return (x>='0'&&x<='9');
	}
    void print()
    {
		cout<<isNumber("0")<<endl;
		cout<<isNumber(" 0.1 ")<<endl;
		cout<<isNumber("abc")<<endl;
		cout<<isNumber("1 a")<<endl;
		cout<<isNumber("2e10")<<endl<<endl;
		
		cout<<isNumber("-1.0e234.5 ")<<endl;
		cout<<isNumber("2.5.4e10")<<endl;
		cout<<isNumber("1e432e12")<<endl;
		cout<<isNumber("-0.2e10")<<endl<<endl;
		
		cout<<isNumber("e")<<endl;
		cout<<isNumber("-0.")<<endl;
		cout<<isNumber("e32")<<endl;
		cout<<isNumber("3214e.342")<<endl;
		
		cout<<isNumber(" 005047e+6")<<endl;
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
