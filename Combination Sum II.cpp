#include<iostream>
#include<string>
#include<vector>
#include <cctype>
#include<algorithm>
#include<math.h>
#include<stack>
using namespace std ;
typedef struct ListNode{
	int val;
	ListNode * next;
} ListNode;
class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int> nums=candidates;
		vector<vector<int> > res;
		vector<vector<int> > vec;
		vector<int> temp;
		int i,j,n,size=nums.size();
		
		if(!size)
			return res;
		sort(nums.begin(),nums.end());
		for(i=0;i<size;i++){
			int foo=nums[i];
			if(foo==target){
				temp.clear();
				temp.push_back(foo);
				for(n=0;n<res.size();n++)
					if(res[n]==temp)
						break;
				if(n>=res.size())
					res.push_back(temp);
				break;
			}
			else if(foo>target)
				break;
			else{
				int len=vec.size();
				for(j=0;j<len;j++){
					temp=vec[j];
					int sum=*(temp.end()-1);
					if(sum+foo>target)
						;//break;
					else if(sum+foo==target){
						*(temp.end()-1)=foo;
						sort(temp.begin(),temp.end());
						for(n=0;n<res.size();n++)
							if(res[n]==temp)
								break;
						if(n>=res.size())
							res.push_back(temp);
					}
					else{
						*(temp.end()-1)=foo;
						temp.push_back(foo+sum);
						vec.push_back(temp);
					}
				}
				temp.clear();
				temp.push_back(foo);
				temp.push_back(foo);
				vec.push_back(temp);
			}
		}
		return res;
    }

    void print()
    {
    	vector<vector<int> > res;
    	int B[]={10,1,2,7,6,1,5,8};
    	vector<int> A(B,B+8);
    	res=combinationSum2(A,8);
    	for(int i=0;i<res.size();i++){
    		for(int j=0;j<res[i].size();j++)
    			cout<<res[i][j]<<" ";
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
