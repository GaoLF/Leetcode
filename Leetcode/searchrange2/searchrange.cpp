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
using namespace std;

class Solution {
public:
    vector<int> searchRange(int A[], int n, int target) {
        int begin,end,middle,cur,i,j;
        begin=0;
        end=n-1;
        middle=(begin+end)/2;
        vector<int> res;
        while(1){
            if(A[middle]<target){
                if(A[end]<target)
                    break;
                else{
                    begin=middle;
                    middle=(begin+end)/2;
                }
            }
            else if(A[middle]>target){
                if(A[begin]>target)
                    break;
                else{
                    end=middle;
                    middle=(begin+end)/2;
                }
            }
            else{
                i=(begin+middle)/2;
                j=(middle+end)/2;
                cur=middle;
                while((i!=begin)&&(i!=cur)&&!((A[i]==target)&&(A[i-1]!=target))){
                    if(A[i]==target){
                        cur=i;
                        i=(begin+cur)/2;
                    }
                    else{
                        begin=i;
                        i=(begin+middle)/2;
                    }
                }
                res.push_back(i);
                cur=middle;
                while((i!=cur)&&(i!=end)&&!((A[i]==target)&&(A[i+1]==target))){
                    if(A[i]==target){
                        cur=i;
                        i=(cur+end)/2;
                    }
                    else{
                        end=i;
                        i=(cur+end)/2;
                    }
                }
                res.push_back(i);
                return res;
            }
            
        }
        res.push_back(-1);
        res.push_back(-1);
        return res;
    }
    void test(){
        int A[10]={1,2,3,4,5,6,7,8,9,9};
        vector<int> B;
        B=searchRange(A,10,6);
        cout<<B[0]<<"  "<<B[1]<<endl;
    }
    
};
int main(){
    Solution C;
    C.test();
}








