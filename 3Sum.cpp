#include <unordered_map>
#include <unordered_set>
#include<iostream>
#include<string>
#include<vector>
#include <cctype>
#include<algorithm>
#include<math.h>

using namespace std ;
typedef struct ListNode{
	int val;
	ListNode * next;
} ListNode;
class Solution {
public:
    vector<vector<int> > threeSum(vector<int> &num) {
        int i,j,size,sum;
        unordered_set<int> map;
		size=num.size();
		vector<vector<int> > res;
		vector<int> cur;
		vector<vector<int> >::iterator iter; 
		
		if(size<3)
			return res;
		for(i=0;i<size;i++)
			map.insert(num[i]);
		for(i=0;i<size;i++){
			if(num[i]>=0){
				for(j=0;j<size;j++){
					if(num[j]<0){
						sum=-(num[i]+num[j]);
						if(map.find(sum)!=map.end()){
							cur.clear();
							cur.push_back(num[i]);
							cur.push_back(num[j]);
						
							if(num[i]==sum){
								if(count(num.begin(),num.end(),num[i])>1)
									cur.push_back(num[i]);
							}
							else if(num[j]==sum){
								if(count(num.begin(),num.end(),num[j])>1)
									cur.push_back(num[j]);
							}		
							else
								cur.push_back(sum);
								
							sort(cur.begin(),cur.end());
							if(cur.size()==3)
								res.push_back(cur);
						}
					}
				}
			}
		}
		if(count(num.begin(),num.end(),0)>2){
			cur.clear();
			cur.push_back(0);
			cur.push_back(0);
			cur.push_back(0);
			res.push_back(cur);
		}
		sort(res.begin(),res.end());
		iter=unique(res.begin(),res.end());	
		res.erase(iter,res.end());
		return res;
    }

    void print()
    {	
    	vector<int> A;
		A.push_back(6);
		A.push_back(-1);
		A.push_back(0);
		A.push_back(1);
		A.push_back(2);
		A.push_back(-1);
		A.push_back(-4);
		A.push_back(-2);
		A.push_back(6);
		vector<vector<int> > B;
		B= threeSum(A);
		cout<<B.size()<<endl;
		for(int i=0;i<B.size();i++){
			for(int j=0;j<B[0].size();j++)
				cout<<B[i][j]<<" ";
			cout<<endl; 
		}
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
