//
//  searchrange.cpp
//  
//
//  Created by Gao on 15-2-16.
//
//

#include <stdio.h>
#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
	bool isScramble(string s1,string s2){
		bool res=1;
		if(s1==s2)
			return 0;
		isCheck(s1,s2,res);
		return res;
	}
	int isCheck(string s1,string s2,bool &res){
		int i,j;//判断两个str是否相同，相同退出，否则
		if (s1==s2)//找第一个不同的字母，然后找到该字母在s2的位置
			return 0;//s1该字母右侧与s2中该字母左侧即交换的部分，比较他们
		if(s1.length()==1&&(s1==s2))
			return 0;
		string cur1=s1;
		string cur2=s2;
		string cur3,cur4;
		sort(cur1.begin(),cur1.end());
		sort(cur2.begin(),cur2.end());
		if(cur1!=cur2){
			res=0;
			return 0;
		}
		for(i=0;i<cur1.length();i++)
			if(s1[i]!=s2[i])
				break;
		for(j=i;j<cur1.length();j++)
			if(s2[j]==s1[i])
				break;
		cur1=string(s1,i+1,j-i+1);
		cur2=string(s2,i,j-i+1);
		cur3=string(s1,j+1,s1.length()-j);
		cur4=string(s2,j+1,s2.length()-j);
		cout<<cur1<<" "<<cur2<<" "<<cur3<<" "<<cur4<<endl;
		isCheck(cur1,cur2,res);
		isCheck(cur3,cur4,res);
        return res;
    }
    void test(){
    	cout<<isScramble("great","rgeat")<<endl;
    	cout<<isScramble("grea","rgeat")<<endl;
    	cout<<isScramble("great","rgtae")<<endl;
    	cout<<isScramble("greab","rgeat")<<endl;
   		cout<<isScramble("abc","cab")<<endl;
	}
};
int main(){
    Solution C;
    C.test();
    system("pause"); 
}








