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
public:
	string multiply(string num1, string num2){
        string res="";
		int i;
		if(num1.length()<num2.length())
			swap(num1,num2);
		if(!(num2.length()))
			return num2;
		if(num1=="0"||num2=="0")
		    return "0";
		for(i=0;i<num2.length();i++){//num1 mul each num of num2, and add 
			sumof(res,num1,num2[i]); //up the sum
		}
		return res;
    }
	void sumof(string &res,string num1,char x){
		int i;
		string cur="0";
		for(i=0;i<(int)(x-'0');i++){
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
      	cout<<multiply("123456","1234567")<<endl;  
      	cout<<multiply("52","60")<<endl; 
	//	cout<<B[0]<<"  "<<B[1]<<endl;
    }
    
};
int main(){
    Solution C;
    C.test();
}








