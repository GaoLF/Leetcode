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
	int firstMissingPositive(int A[],int n){
        int flag[65536]={0};//我晕，这个题比想象中简单不少，只需要从0开始找第一个没有的正整数即可！
		int i;
		int step=65536;
		if(!n)
			return 1;
		int minvalue=A[0];
		for(i=0;i<n;i++){
			if(A[i]>0&&(A[i]<step)){
				flag[A[i]]=1;
			}
		}
		for(i=1;i<n+1;i++){
			if(!flag[i])
				return i;
		}
		return i;	
        /*	          
		int flag[65536]={0};
		int i;
		int step=65536;
		if(!n)
			return 1;
		int minvalue=65536;
		for(i=0;i<n;i++){
			if(A[i]>0)
				minvalue=min(minvalue,A[i]);
		}
		if(minvalue==65536)
            return 1;
		for(i=0;i<n;i++){
			if(A[i]>0&&(A[i]-minvalue<step)){
				flag[A[i]-minvalue]=1;
			}
		}
		for(i=0;i<n+1;i++){
			if(!flag[i])
				return i+minvalue;
		}
		return n+minvalue;
		*/
    }
    void test(){
        int A[10]={1,2,3,4,5,6,7,8,9,0};
		int C[5]={3,4,-1,1,0};
        vector<int> B;
       // cout<<B[0]<<"  "<<B[1]<<endl;
	    cout<<firstMissingPositive(A,1)<<endl;		          
	    cout<<firstMissingPositive(C,4)<<endl;
	}
};
int main(){
    Solution C;
    C.test();
    system("pause"); 
}








