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
#include <algorithm>
using namespace std;

class Solution {
public://this func can not remove the duplicate ones.
	vector<vector<int> > fourSum(vector<int> &num,int target){ 
		vector<vector<int> > res,sumoftwo;
		vector<int> cur_sumoftwo;
		int i,j,m,n;
		int Sumoftwo[100][100]={0};
		if (num.size()<4)
			return res;
		for(i=0;i<num.size();i++)
			for(j=0;j<num.size();j++)
				Sumoftwo[i][j]=num[i]+num[j];
		for(i=0;i<num.size();i++){
			for(j=i+1;j<num.size();j++){
				for(m=j+1;m<num.size();m++){
					for(n=m+1;n<num.size();n++){
						if(Sumoftwo[i][j]+Sumoftwo[m][n]==target){
							vector<int> a;
							a.push_back(num[i]);
							a.push_back(num[j]);
							a.push_back(num[m]);
							a.push_back(num[n]);
							sort(a.begin(),a.end());
							res.push_back(a);
						}
					}
				}
			}
		}
		/*
		for(i=0;i<num.size();i++){
			for(j=0;j<num.size();j++){
				vector<int > a;// I forget how to clear the vector
				a.push_back(num[i]+num[j]);//so I submit a vector every loop
			}
			sumoftwo.push_back(a);
		}*/

        return res;
    }
    void test(){
        int A[10]={1,2,3,4,5,6,7,8,9,9};
        vector<int> B;
		vector<vector<int> > res;
		B.push_back(1);
		B.push_back(0);
		B.push_back(-1);
		B.push_back(0);
		B.push_back(-2);
		B.push_back(2);
		res=fourSum(B,0);
		for(int i=0;i<res.size();i++){
			for(int j=0;j<res[i].size();j++)
				cout<<res[i][j]<<" ";
			cout<<endl;
		}
    }
    
};
int main(){
    Solution C;
    C.test();
    system("pause"); 
}








