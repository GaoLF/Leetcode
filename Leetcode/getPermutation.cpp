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
	string getPermutation(int n,int k){
		int mul=multi(n-1);//n-1的阶乘
		int i,j;
		int count=0;
		int flag[10]={0};//存储前j个数有几个已经被列举到
		string res="";
		if(n==1)
		  return "1";
		for(i=0,k--;i<n;i++){
			int looptimes=k/mul;
			for(j=0,count=0;(j<looptimes)||flag[j];j++){
				if(flag[j]){//如果该数已经用到，则循环往后移一位，count+1
					count++;
					looptimes++;
		//			while(flag[++j])
		//				count++;
				}
			}
			while(flag[j++])
				count++;
			flag[count+k/mul]=1;
			res+=('1'+ count+k/mul);//加上的一位综合考虑之前用到了多少
			k=(k%mul);
			if(n-1>i)
				mul=mul/(n-i-1);
	//		else
	//			mul=1;
		}
        return res;
    }
	int multi(int n){
		int i,res;
		if(!n)
			return 0;
		for(i=1,res=1;i<=n;i++)
			res*=i;
		return res;
	}
    void test(){
//        int A[10]={1,2,3,4,5,6,7,8,9,9};
        cout<<getPermutation(1,1)<<endl;
		cout<<getPermutation(2,1)<<endl;
		cout<<getPermutation(2,2)<<endl;
		cout<<getPermutation(2,3)<<endl;
		cout<<getPermutation(2,4)<<endl;
		cout<<getPermutation(5,4)<<endl;
		cout<<getPermutation(5,5)<<endl;
		cout<<getPermutation(5,6)<<endl;
		cout<<getPermutation(5,7)<<endl;
		cout<<getPermutation(5,8)<<endl;
		cout<<getPermutation(5,9)<<endl;
		cout<<getPermutation(5,10)<<endl;
		cout<<getPermutation(5,11)<<endl;
		cout<<getPermutation(5,12)<<endl;
		cout<<getPermutation(5,13)<<endl;
		cout<<getPermutation(5,14)<<endl;
		cout<<getPermutation(5,15)<<endl;
		cout<<getPermutation(5,16)<<endl;
    }
    
};
int main(){
    Solution C;
    C.test();
    system("pause");
}








