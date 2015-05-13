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
    int compareVersion(string version1, string version2) {
        string sub1_pre,sub1_suf;
        string sub2_pre,sub2_suf;
		int res;
		
    	while(!(version1=="0"&&version2=="0")){
    		split(version1,sub1_pre,sub1_suf);
        	split(version2,sub2_pre,sub2_suf);
        	res=compare(sub1_pre,sub2_pre);
        	if(res==1)
        		return 1;
        	else if(res==-1)
        		return -1;
        	else{
        		version1=sub1_suf;
        		version2=sub2_suf;

			}
		}
		return 0;
    }
    int compare(string A,string B){
    	if(A.length()>B.length())
    		B=string(A.length()-B.length(),'0')+B;
    	else
    		A=string(B.length()-A.length(),'0')+A;
		if(A>B)
    		return 1;
    	if(A==B)
    		return 0;
    	if(A<B)
    		return -1;
	}
	void split(string version,string &sub_pre,string &sub_suf){
		int i,size=version.length();
        for(i=0;i<size;i++)
        	if(version[i]=='.')
        		break;
        if(i==0){
        	sub_pre="0";
        	sub_suf=version;
		}
        else if(i==size){
        	sub_pre=version;
        	sub_suf="0";
        }
        else if(i==(size-1)){
        	sub_pre=version.substr(0,size-1);
        	sub_suf="0";
		}
		else{
			sub_pre=version.substr(0,i);
        	sub_suf=version.substr(i+1,size-i);
		} 
	}
    void print()
    {
		cout<<compareVersion("1.0","1.1")<<endl;
		cout<<compareVersion("19.8.3.17.5.01.0.0.4.0.0.0.0.0.0.0.0.0.0.0.0.0.00.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.000000",\
		"19.8.3.17.5.01.0.0.4.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0000.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0")<<endl;
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
