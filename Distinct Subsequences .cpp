#include<iostream>
#include<string>
#include<vector>
#include <cctype>
#include<algorithm>
#include<math.h>
#include<unordered_map>
using namespace std ;
typedef struct ListNode{
	int val;
	ListNode * next;
} ListNode;
class Solution {
public:
	int numDistinct(string s, string t) {
		int size1=s.length();
		int size2=t.length();
		int i,j,res=0;
		if(!size2)
			return 0;
		int flag[30];
		for(i=0;i<30;i++)
			flag[i]=0;
		for(i=0;i<size1;i++){
			char temp=s[i];
			for(j=0;j<size2;j++){
				if(j>0&&flag[j]==0&&flag[j-1]==0)
					break;

			}
			for(j=j-1;j>=0;j--){
				if(temp==t[j]){
					if(!j)
						flag[j]++;
					else 
						flag[j]+=flag[j-1];
				}
			}
		}
		return flag[size2-1];
	}
	/*
	unordered_map<int ,int> map;
    int numDistinct(string s, string t) {
    	
        int cur;
		int i,j,res=0;
		int size1=s.length();
		int size2=t.length();
	//	cout<<s<<" "<<t<<endl;
		unordered_map<int,int>::iterator iter=map.find(size1<<3+size2);
		if(iter!=map.end())
			return iter->second;
		if(s==t)
			return 1;
		if(size1<=size2)
			return 0;
		for(i=0;i<size1;i++){
			if(s[i]==t[0]){
				if(size2==1)
					res+= 1;
				else if(i+1<size1)	
					res+= numDistinct(s.substr(i+1,size1-i-1),t.substr(1,size2-1));
			}
		}
		for(j=0;i<size1&&s[i]!=t[0];i++)
			map.insert(make_pair((size1-i)<<3+(size2),res));
		return res;
		
    }*/
    void print()
    {
	//	cout<<numDistinct("daacaedaceacabbaabdccdaaeaebacddadcaeaacadbceaecddecdeedcebcdacdaebccdeebcbdeaccabcecbeeaadbccbaeccbbdaeadecabbbedceaddcdeabbcdaeadcddedddcececbeeabcbecaeadddeddccbdbcdcbceabcacddbbcedebbcaccac","ceadbaa")<<endl;
		cout<<numDistinct("rabbbitt","rbt")<<endl;
		cout<<numDistinct("rabbbitt","rat")<<endl;
		cout<<numDistinct("rabbbitt","ra")<<endl;
		cout<<numDistinct("aaaaaaaaaaaaa","aaa")<<endl;
		cout<<numDistinct("aaaa","aaa")<<endl;
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
