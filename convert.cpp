#include<iostream>
#include<string>
using namespace std;

class Solution {
public:
    string convert(string s, int nRows) {
		if(s=="")
			return s;
			
        string cur;
        int a,b;
//        cout<<s.length();
        int size=(s.length()+2*nRows-2-1)/(2*nRows-2);
        for(int i=0;i<nRows;i++)
            for(int j=0;j<size;j++)
            {
				a=i+j*(2*nRows-2);
				b=(j+1)*(2*nRows-2)-i;
                if(a<s.length())
              		cur+=s[a];
                if(i!=0&&i!=nRows-1)
                    if(b<s.length())
                   		cur+=s[b];
            }
        return cur;
    }
};
int main()
{
	Solution a;
	//cout<<a.convert("A",1)<<endl;
	string b="1233";
//	cout<<atoi(b.c_str())+1<<endl;
	int c=3;
	cout<<b+int2str(c)<<endl;
	system("pause");
} 
