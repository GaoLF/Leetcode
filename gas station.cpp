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
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
        int start=0, size=gas.size();
        int iter,flag=0;
        int tank;
		while(start<size){
			tank=0;
			for(iter=start;1;iter++){
				tank+=gas[iter];
				tank-=cost[iter];
				if(tank<0){
					if(flag/*(iter+1)<start*/)
						return -1;
					start=iter+1;
					break;
				}
				else{
					if(((iter+1)%size)==start)
						return start;
					if(iter==size-1){
						iter=-1;
						flag=1;
					}
				}
			}
		} 
		return -1;
    }


    void print()
    {
    	vector<int> gas;
    	vector<int> cost;
    	gas.push_back(1);
    	gas.push_back(2);
    	gas.push_back(3);
    	cost.push_back(1);
    	cost.push_back(3);
    	cost.push_back(2);
    	cout<<canCompleteCircuit(gas,cost)<<endl;

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
