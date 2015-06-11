#include<iostream>
#include<string>
#include<vector>
#include <cctype>
#include<algorithm>
#include<math.h>
#include<unordered_set>
using namespace std ;
typedef struct ListNode{
	int val;
	ListNode * next;
} ListNode;
class Solution {
public:
	//method 1:
	//其实我是觉得适用于不同的情况，方法一适用于，单词多，单词长度短。
	//方法二适用于单词少，单词长度长，本题中方法二会超时，但是方法1也不快，应该有更好的方法 
	    int ladderLength(string beginWord, string endWord, unordered_set<string>& wordDict) {
        unordered_set<string> tempset,temp2set;  
        unordered_set<string>::iterator iter,iter2,iter3;
        int i,j,m,size,res=1,set_size;
        
        tempset.insert(beginWord);
        
		if((!check(beginWord,endWord))&&(beginWord!=endWord)){
        	for(iter=wordDict.begin();iter!=wordDict.end();iter++)
        		if(check(endWord,*iter))
        			break;
            if(iter==wordDict.end())
        	    return 0;
		}
        	
		while(!tempset.empty()&&(!wordDict.empty())){
			int length=(tempset.begin())->length();
			for(iter2=tempset.begin();iter2!=tempset.end();iter2++){
				string bar=*iter2;
				if(bar==endWord)
					return res;
				if(check(endWord,bar))
					return res+1;
				for(j=0;j<length;j++){
					for(m='a';m<='z';m++){
						int tempchar=bar[j];
						bar[j]=m;
						if(wordDict.find(bar)!=wordDict.end()){
							temp2set.insert(bar);
						}
						bar[j]=tempchar;
					}
				}
				wordDict.erase(bar);
			}
			tempset.clear();
			tempset.swap(temp2set);
			//temp2set.clear();
			res++;
		}
		return 0;
    }
	bool check(string A, string B){
		int flag=0;
		int size=A.length();
		for(int i=0;i<size;i++){
			if(A[i]!=B[i])
				flag++;
			if(flag>1)
				return 0;
		}
		return 1;
	}
	//method 1:
	/*
    int ladderLength(string beginWord, string endWord, unordered_set<string>& wordDict) {
        unordered_set<string> tempset,temp2set;  
        unordered_set<string>::iterator iter,iter2,iter3;
        int i,j,m,size,res=1,set_size;
        
        tempset.insert(beginWord);
    
		if(!check(beginWord,endWord))
        	for(iter=wordDict.begin();iter!=wordDict.end();iter++)
        		if(check(endWord,*iter))
        			break;
        if(iter==wordDict.end())
        	return 0;
        	
		while(!tempset.empty()&&(!wordDict.empty())){
			int length=(tempset.begin())->length();
			for(iter2=tempset.begin();iter2!=tempset.end();iter2++){
				string bar=*iter2;
				if(bar==endWord)
					return res;
				if(check(endWord,bar))
					return res+1;
				for(j=0;j<length;j++){
					for(m='a';m<='z';m++){
						int tempchar=bar[j];
						bar[j]=m;
						if(wordDict.find(bar)!=wordDict.end()){
							temp2set.insert(bar);
						}
						bar[j]=tempchar;
					}
				}
				wordDict.erase(bar);
			}
			tempset.clear();
			tempset.swap(temp2set);
			//temp2set.clear();
			res++;
		}
		return 0;
    }
	bool check(string A, string B){
		int flag=0;
		int size=A.length();
		for(int i=0;i<size;i++){
			if(A[i]!=B[i])
				flag++;
			if(flag>1)
				return 0;
		}
		return 1;
	}*/
    void print()
    {
		unordered_set<string> A;		
		A.insert("hot");
		A.insert("dot");
		A.insert("dog");
		A.insert("lot");
		A.insert("log");
		string B,C;
		B="hit";
		C="hit";
		cout<<ladderLength(B,C,A)<<endl;
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
