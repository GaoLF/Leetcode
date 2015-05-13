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
	unordered_map<int ,int> map;
    int numDistinct(string s, string t) {
    	int res;
    	int i,j;
    	int size1=s.length();
    	int size2=t.length();
    	int matrix[200][20]={0};
    	for(i=0;i<size1;i++){
    		for(j=0;j<size2;j++){
    			if()
			}
		}
    	/*
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
		for(i=0;i<size1&&s[i]!=t[0];i++)
			map.insert(make_pair((size1-i)<<3+(size2-j),res));
		return res;
		*/
    }
    void print()
    {
		cout<<numDistinct("daacaedaceacabbaabdccdaaeaebacddadcaeaacadbceaecddecdeedcebcdacdaebccdeebcbdeaccabcecbeeaadbccbaeccbbdaeadecabbbedceaddcdeabbcdaeadcddedddcececbeeabcbecaeadddeddccbdbcdcbceabcacddbbcedebbcaccac","ceadbaa")<<endl;
	//	cout<<numDistinct("rabbbitt","rbt")<<endl;
	//	cout<<numDistinct("rabbbitt","rat")<<endl;
	//	cout<<numDistinct("rabbbitt","ra")<<endl;
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
