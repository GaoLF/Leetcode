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
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
		int size1=nums1.size();
		int size2=nums2.size();
		int iter1=0,iter2=0;
		int term=(size1+size2)/2;
		int flag=(size1+size2)%2;//0Õû³ý£¬ 1ÓÐÓàÊý 
		if(!(size1+size2))
			return 0;
			
		if(!size1){
			if(flag)
				return nums2[term];
			else
				return (double)(nums2[term]+nums2[term-1])*0.5;
		}
		if(!size2){
			if(flag)
				return nums1[term];
			else
				return (double)(nums1[term]+nums1[term-1])*0.5;
		}
		
		while(1){
			if(iter1==size1){
				swap(nums1,nums2);
				swap(size1,size2);
				swap(iter1,iter2);				
			}		
			if(iter2==size2){
				int temp=term-size2;
				
				if(flag)
					return nums1[temp];
				else {
					int foo;
					if(size2&&(!temp))
						foo=nums2[size2-1];
					else if(!size2&&temp)
						foo=nums1[temp-1];
					else
						foo=(max(nums1[temp-1],nums2[size2-1]));
					return (double)(foo+nums1[temp])*0.5;
				}
					//cout<<temp<<" "<<iter1<<" "<<iter2<<endl;
				
			}
			if(nums2[iter2]<nums1[iter1]){
				swap(nums1,nums2);
				swap(size1,size2);
				swap(iter1,iter2);
			}
			for(;(iter1<size1)&&(nums1[iter1]<=nums2[iter2]);iter1++){
				if(iter1+iter2>=term){
					int temp;
					if(flag)
						return nums1[iter1];
					else{
						if(iter1&&iter2)
							temp=max(nums1[iter1-1],nums2[iter2-1]);
						else if(!iter1&&iter2)
							temp=nums2[iter2-1];
						else if(iter1&&(!iter2))
							temp=nums1[iter1-1];
					//	else	
					//		temp=0;
						return (double)(nums1[iter1]+temp)*0.5;
					}
				}
			}	
		}
    }

    void print()
    {
		vector<int> A,B;
		cout<<findMedianSortedArrays(A,B)<<endl;
		A.push_back(0);
		cout<<findMedianSortedArrays(A,B)<<endl;
		A.push_back(1);
		cout<<findMedianSortedArrays(A,B)<<endl;
		A.push_back(2);
		cout<<findMedianSortedArrays(A,B)<<endl;
		B.push_back(3);
		cout<<findMedianSortedArrays(A,B)<<endl;
		B.push_back(4);
		cout<<findMedianSortedArrays(A,B)<<endl;
		B.push_back(5);
		B.push_back(6);
		B.push_back(7);
		B.push_back(8);
		B.push_back(9);
		cout<<findMedianSortedArrays(A,B)<<endl;
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
