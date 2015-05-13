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
        int size,count=0,cur1,cur2,size1,size2,cur,cur3,f; 
		int i=0,j=0,iflag=0,jflag=0,flag=0;
		size1=nums1.size();
		size2=nums2.size();
		size=size1+size2;
		
		if(size1)
			iflag=1;
		else if(size2)
			jflag=1;
		while(1){
			cur1=cur;
			if(iflag){
				if(i+1<size1)
					cur2=nums1[i+1];
				if(j<size2)
					cur3=nums2[j];
				if(i+1<size1&&(j+1>=size2||cur2<cur3))
					cur=nums1[++i];
				else{
					cur=cur3;
					swap(iflag,jflag);
					f=1;
				}	

			}
			else if(jflag){
				if(j+1<size2)
					cur2=nums2[j+1];
				if(i<size1)
					cur3=nums1[i];
				if(j+1<size2&&(i+1>=size1||cur2<cur3))
					cur=nums2[++j];
				else{
					cur=cur3;
					swap(iflag,jflag);
				}
				
			}
			if(size==1)
				return size1?nums1[0]:nums2[0];
			if(count>=(size/2)){
				if(size%2==0){
					return (double)(cur1+cur)/2;
				}
				else
					return cur;
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
