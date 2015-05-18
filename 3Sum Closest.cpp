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
	int threeSumClosest(vector<int>& nums, int target) {
    	int i,j,m,size=nums.size();
		int res;
		int diff=1<<15;
		if(size<3)
			return 0;
		res=nums[0]+nums[1]+nums[2];
		diff=abs(res-target);
		sort(nums.begin(),nums.end()); 
		
		int foo=nums[0]+nums[1]+nums[2];
		int bar=nums[size-2]+nums[size-1]+nums[size-3];
		if(foo>=target)
		    return foo;
		if(bar<=target)
		    return bar;
       	for(i=0;i+2<size;i++){
       		int temp1=nums[i]+nums[i+1]+nums[i+2];
       		int temp2=nums[i]+nums[size-2]+nums[size-1];
			if(temp1>target)
				break;
			else if(temp2<target){
				if(abs(temp2-target)<diff){
					res=temp2;
					diff=abs(temp2-target);
				}		
			} 
			else{
				for(j=i+1;j+1<size;j++){
					int temp3=nums[i]+nums[j]+nums[j+1];
					int temp4=nums[i]+nums[j]+nums[size-1];
					if(temp3>target)
						break;
					else if(temp4<target){
						if(abs(temp4-target)<diff){
							res=temp4;
							diff=abs(temp4-target);
						}	
					}		
					else{
						for(m=j+1;m<size;m++){
							int temp5=nums[i]+nums[j]+nums[m];
							if(abs(temp5-target)<diff){
								diff=abs(temp5-target);
								res=temp5;
							}
								
							if(temp5==target)
								return target;
						}
					} 
				}
			}
	   	}
    
       return res;
    }
    void print()
    {
    	vector<int> A;
    	A.push_back(0);
    	A.push_back(2);
    	A.push_back(1);
    	A.push_back(-3);
		cout<<threeSumClosest(A,1)<<endl;
    	int X[500]={43,75,-90,47,-49,72,17,-31,-68,-22,-21,-30,65,88,-75,23,97,-61,53,87,-3,33,20,51,-79,43,80,-9,34,-89,-7,93,43,55,-94,29,-32,-49,25,72,-6,35,53,63,6,-62,-96,-83,-73,66,-11,96,-90,-27,78,-51,79,35,-63,85,-82,-15,100,-82,1,-4,-41,-21,11,12,12,72,-82,-22,37,47,-18,61,60,55,22,-6,26,-60,-42,-92,68,45,-1,-26,5,-56,-1,73,92,-55,-20,-43,-56,-15,7,52,35,-90,63,41,-55,-58,46,-84,-92,17,-66,-23,96,-19,-44,77,67,-47,-48,99,51,-25,19,0,-13,-88,-10,-67,14,7,89,-69,-83,86,-70,-66,-38,-50,66,0,-67,-91,-65,83,42,70,-6,52,-21,-86,-87,-44,8,49,-76,86,-3,87,-32,81,-58,37,-55,19,-26,66,-89,-70,-69,37,0,19,-65,38,7,3,1,-96,96,-65,-52,66,5,-3,-87,-16,-96,57,-74,91,46,-79,0,-69,55,49,-96,80,83,73,56,22,58,-44,-40,-45,95,99,-97,-22,-33,-92,-51,62,20,70,90};
    	vector<int > B(X,X+500);
    	for(int i=0;i<B.size();i++)
    		cout<<B[i]<<" ";
    	cout<<endl;
		cout<<threeSumClosest(B,284)<<endl;

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
