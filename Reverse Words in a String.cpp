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
    void reverseWords(string &s) {
        string res="";
        int i,j;
        for(i=s.length()-1,j=i;i>=-1;i--){
            if(s[i]==' '||i==-1){
            	if(res!=""&&i!=j)
            		res+=" ";
            	res+=(s.substr(i+1,j-i));
                j=i-1;
            }
        }
        s=res;
    }

    void print()
    {
    	string s=" I    am a  dog ";
    	//string s="a ";
    	reverseWords(s);
		cout<<"-->"<<s<<"<--"<<endl; 
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
