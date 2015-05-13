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
 int maximumGap(vector<int>& nums) {
    int i,j,min_v,max_v;
    
    if(nums.size() < 2){
        return 0;
    }
    
    // Find the min and max elements in the list.
    min_v=max_v=nums[0];
    for(i=0;i<nums.size();i++){
        min_v = min(min_v, nums[i]);
        max_v = max(max_v, nums[i]);
    }
	
    // Put the n elements into (n-1) buckets. 
    double div = (max_v-min_v)*1.0/(nums.size()-1);
    // bucket[i]  : min value in the bucket i/2;
    // bucket[i+1]: max value in the bucket i/2;
    // Note: the elements are all non-negatives.
    int *bucket = (int*)malloc(sizeof(int)*nums.size()*2);
    for(i=0;i<nums.size()*2;i++)
    	bucket[i]=0;
    for(i=0;i<nums.size();i++){
        j = (int)((nums[i]-min_v)/div) * 2;

        bucket[j]   = bucket[j] == 0 ? nums[i] : min(nums[i], bucket[j]);
        bucket[j+1] = bucket[j+1] == 0 ? nums[i] : max(nums[i], bucket[j+1]);
    }

    // Calculate the maximum distance between buckets, 
    //  which is aslo the maximum gap between elements.
    int last_bound = min_v;
    int max_gap = 0;
    for(i=0; i<nums.size()*2; i+=2){
        if(bucket[i] == 0){
            // no element in this bucket.
            continue;
        }
		cout<<bucket[i]<<" "<<last_bound<<endl;
        max_gap = max(bucket[i]-last_bound, max_gap);
        last_bound = bucket[i+1];
    }

    return max_gap;
}


    void print()
    {
		vector<int > A;
		A.push_back(1);
	
		A.push_back(10000000);
		//A.push_back(9);
		//A.push_back(1);
		cout<<maximumGap(A)<<endl;
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
