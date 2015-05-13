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
	string multiply(string num1, string num2){
        string res="";
		int i;
		if(num1.length()<num2.length())
			swap(num1,num2);
		if(!(num2.length()))
			return num2;
		for(i=0;i<num2.length();i++){//num1 mul each num of num2, and add 
			sumof(res,num1,num2[i]); //up the sum
		}
		return res;
    }
	void sumof(string &res,string num1,char x){
		int i;
		string cur=num1;
		for(i=0;i<(int)(x-'0'-1);i++){
			cur=sum(cur,num1);
		}
		res=sum(cur,res+"0");
	}
	string sum(string A,string B){
		int i,flag;
		char cur;
		flag=0;
		if(A.length()>B.length())
			swap(A,B);
		A=string(B.length()-A.length(),'0')+A;
		for(i=B.length()-1;i>=0;i--){
			cur=B[i]+A[i]+flag-'0';
			if(cur>'9'){
				flag=1;
				cur=cur-10;
			}
			else
				flag=0;
			B[i]=cur;
		}
		if(flag)
			B="1"+B;
		return B;
	}
    void test(){
      	cout<<sum("123456","123456")<<endl;  
		cout<<multiply("1323243245675823","28768567534028327357435834")<<endl;
    }
    
};
int main(){
    Solution C;
    C.test();
}








