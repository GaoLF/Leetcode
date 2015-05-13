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
    vector<string> letterCombinations(string digits) {
        vector<string> res;
        if(digits.length()==0)
            return res;
        res.push_back("");
        for(int i=0;i<digits.length();i++)
            deal(res,digits[i]);     
        return res;
    }
    int deal(vector<string> &A,char c){
        int i,size;
        string cur_str;
        char cur_char;
//      vector<string>::iterator iter,iter_end;
        size=A.size();
        for(i=0;i<size;i++){
            if(c<='7'&&c>='2'){
                cur_str=A[i];
                cur_char=3*(c-'2')+'a';
                A.push_back(cur_str+char(cur_char+1));
                A.push_back(cur_str+char(cur_char+2));
                A[i]+=cur_char;
                if(c=='7')
                    A.push_back(cur_str+char(cur_char+3));               
            }
            else if(c=='8'||c=='9'){
                cur_str=A[i];
                cur_char=3*(c-'2')+'a'+1;
                A.push_back(cur_str+char(cur_char+1));
                A.push_back(cur_str+char(cur_char+2));
                A[i]+=cur_char;
                if(c=='9')
                    A.push_back(cur_str+char(cur_char+3));
            }
            else if(c=='*')
                A[i]+="+";
            else if(c=='0')
                A[i]==" ";
            else
                return 0;
        }
    }
    void test(){
        vector<string> res=letterCombinations("9");
        for(int i=0;i<res.size();i++){
            cout<<res[i]<<endl;       
        }
    }
    
};
int main(){
    Solution C;
    C.test();
    system("pause");
}








