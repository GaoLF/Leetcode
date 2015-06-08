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
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
        if(A>E){
        	swap(A,E);
        	swap(B,F);
        	swap(C,G);
        	swap(D,H);
		} 
		int res=(C-A)*(D-B)+(G-E)*(H-F);
		if(B<=F&&E<=C&&F<=D)
			if(G>=A&&G<=C)
				if(H<=D)
					if(A==E&&B==F&&C==G&&D==H)
						return res/2;
					else
						return (C-A)*(D-B);
				else 
					return res-(G-E)*(D-F);
			else 
				if(H<=D)
					return res-(H-F)*(C-E);
				else
					return res-(C-E)*(D-F);
		if(H>=B&&E<=C&&H<=D)
			if(G>=A&&G<=C)
				return res-(H-B)*(G-E);
			else
				return res-(H-B)*(C-E);
		if(E>=A&&E<=C)
			if(G<=C)
				return res-(G-E)*(D-B);
			else
				return res-(C-E)*(D-B);
		return res;
    }

    void print()
    {
    	cout<<computeArea(-3,0,3,4,0,-1,9,2)<<endl;
    	cout<<computeArea(-3,0,3,4,-3,0,3,4)<<endl;
    	cout<<computeArea(0,0,0,0,-1,-1,1,1)<<endl;
    	cout<<computeArea(-2, -2, 2, 2, -3, -3, 3, -1)<<endl;
    	cout<<computeArea(-2, -2, 2, 2, 2, -2, 4, 2)<<endl;
    	cout<<computeArea(-2, -2, 2, 2, -1, -1, 1, 1)<<endl;
    	cout<<computeArea(-2, -2, 2, 2, 1, -3, 3, 3)<<endl;
    	cout<<computeArea(-2, -2, 2, 2, -3, -3, -1, 3)<<endl;


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
