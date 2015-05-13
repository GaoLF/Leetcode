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
	struct Point {
      	int x;
      	int y;
    	Point() : x(0), y(0) {}
     	Point(int a, int b) : x(a), y(b) {}
 	};
    int maxPoints(vector<Point>& points) {
        int size=points.size();
		int i,j,res=0;
		float flag,a,b;//xielv jieju
		unordered_map<float,int> map;
		
		if(size<=1)
			return 1;
		
		for(i=0;i<size;i++){
			for(j=i+1;j<size;j++){
				
			}
		} 
    }

    void print()
    {

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
