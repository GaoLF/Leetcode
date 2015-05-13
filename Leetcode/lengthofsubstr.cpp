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
	int lengthOfLongestSubstring(string s) {
		int head,len,i,j,res=0,count;
		if(s.length()==1)
			return 1;
		for(len=0,head=0,i=1;i<s.length();i++){
			for(j=head;j<i;j++){
				if(s[j]==s[i]){
					head=j+1;
					break;
				}

   			//	if((i-j+1)>res){
   			//		cout<<i<<" "<<j<<" "<<res<<endl;
			//		res=i-j+1;
				//	if(j==i-1&&s[j]!=s[i])
				//		res++;
			//	}

			}
			if(i-head+1>res)
				res=i-head+1;
		}
        return res;
    }
    void test(){
       // int A[10]={1,2,3,4,5,6,7,8,9,9};
        vector<int> B;
      //  B=searchRange();
	  	string C="abcdddcseadd";
		string D="abcd";
		string E="au";
		cout<< lengthOfLongestSubstring(C) <<endl;
		cout<< lengthOfLongestSubstring(D) <<endl;
		cout<< lengthOfLongestSubstring(E) <<endl;
    }
    
};
int main(){
    Solution C;
    C.test();
}








