#include<iostream>
#include<string>
#include<vector>
#include <cctype>
#include<algorithm>
#include<unordered_map>
#include<math.h>
using namespace std ;
typedef struct ListNode{
	int val;
	ListNode * next;
} ListNode;
class Solution {
public: 
	unordered_map<int,int> cur_map;
    int minDistance(string word1,string word2){
		int i,j;
		int size1=word1.length();
		int size2=word2.length();

		int XX[600][600]={0}; 
		for(i=0;i<size1;i++)
			XX[i+1][0]=i+1;
		for(j=0;j<size2;j++)
			XX[0][1+j]=j+1;
		for(i=0;i<size1;i++){
			for(j=0;j<size2;j++){
				if(word2[j]==word1[i]){	
						XX[i+1][j+1]=XX[i][j];
				}
				else{
						XX[i+1][j+1]=min(XX[i][j]+1,XX[i+1][j]+1);
						XX[i+1][j+1]=min(XX[i+1][j+1],XX[i][j+1]+1);
				}
			}
		} 

		return XX[size1][size2];
		
    	/*递归方法，复杂度太大 
    	int i,j,p;
    	int size1=word1.length(),size2=word2.length();
    	int res=max(size1,size2);
    	string cur1,cur2;
    	unordered_map<int,int>::iterator x=cur.find(size1<<4+size2);
    	if(x!=cur.end()){
    		cout<<size1<<" "<<size2<<"->"<<x->second<<endl;
    		return x->second;
		}
    		
    	for(i=0;i<size1;i++){
    		for(j=0;j<size2;j++){
    			if(word1[i]==word2[j]){
    				cur1=word1.substr(i+1,size1-i+1);
    				cur2=word2.substr(j+1,size2-i+1);
    				res=min(res,max(i,j)+minDistance(cur1,cur2));
				}
			}
		}
		p=size1<<4+size2;
		cur.insert(make_pair(p,res));
		return res;
	//	*/ 
	}

    void print()
    {
    	string w ="";
		string w1="a";
		string w2="axxacde";
		string w3="ax";
		string w4="abe";
		string w5="babd";
		string w6="abcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdef";
		string w7="bcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefg";
		cout<<minDistance(w,w1)<<endl;
		cout<<minDistance(w2,w3)<<endl;
		cout<<minDistance(w4,w5)<<endl;
		cout<<minDistance(w6,w7)<<endl;
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
