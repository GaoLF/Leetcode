#include<iostream>
#include<string>
#include<vector>
using namespace std ;
class Solution {
public:
    int atoi(const char *str) {
		int opflag=0;
		int res=0;
		if(!*str) 
			return 0;
		if(*str==' ')
			while(*str==' ')
				str=str+1;
		if(*str=='+')
			if(!*(str++))
				return 0;
			else ;
		else if(*str=='-')
			if(*(++str))
				opflag=1;
			else
				return 0;
		while(isdigit(*str))
		{
			if((res==214748364&&(*str-'0')>7)||(res>214748364&&isdigit(*str)))
				if(opflag==0)
					return 2147483647;
				else 
					return -2147483648;
			res=res*10+(*str-'0');
			str+=1;
			
		}
		if(opflag)
			res=-res;
		return res;
	}
	/*
		if(!*str) 
			return 0;
		if(*str==' ')
			while(*str==' ')
				str=str+1;
		if(!*(str+1)&&!isdigit(*str))
			return 0;
		for(int j=0;*(str+j);j++)
		{
			if(!j&&!(isdigit(*str)||*str=='-'||*str=='+'))
				return 0; 
			if(j&&(!isdigit(*(str+j)))) 
				return 0;
		}
		int i,res=0;
        for(i=0;*(str+i)>'9'||*(str+i)<'1';i++);
        for(int j=i;*(str+j);j++)
        	res=res*10+(*(str+j)-'0');
        if(*str=='-')
        	res=0-res;
        return res;
    }*/
    bool isdigit(char x)
    {
		if(x>='0'&&x<='9')
			return 1;
		else
			return 0;
	}
};
int main()
{
	Solution test;
	cout<<test.atoi("-2147483648")<<endl;
	cout<<atoi("2147483648")<<endl;
	system("pause");
}
