#include<iostream>
#include<string>
#include<vector>
#include <cctype>
#include<algorithm>
#include<math.h>
#include<unordered_set>
#include<stack>
using namespace std ;
typedef struct ListNode{
	int val;
	ListNode * next;
} ListNode;
class Solution {
public:
//	bool canFinish2(int numCourses, vector<pair<int, int> >& prerequisites) { 
		
//	}
    bool canFinish(int numCourses, vector<pair<int, int> >& prerequisites) { 
		int i,j,foo,bar,res;
		unordered_set<int> temp;
		vector<unordered_set<int> > graph(numCourses,temp);
		vector<int> flag(numCourses,0);

		for(i=0;i<prerequisites.size();i++){
			graph[prerequisites[i].second].insert(prerequisites[i].first);
		}
		for(i=0;i<numCourses;i++){
			stack<int> cur;
			for(auto it = graph[i].begin(); it != graph[i].end(); ++it)
				cur.push(*it);
			while(!cur.empty()){
				foo=cur.top();
			//	cout<<foo<<endl;
				cur.pop();
				if(flag[foo]==0){		
					for(auto iter = graph[foo].begin(); iter != graph[foo].end(); ++iter){
						bar=*iter;
						if(bar==i)
							return 0;
						if(graph[i].find(bar)==graph[i].end()){
							cur.push(bar);
							graph[i].insert(bar);
						}
					}
				}
			} 
			flag[i]=1;
		}
		return 1;
    }
    void print()
    {
		vector<pair<int, int> > A;
		A.push_back(make_pair(0,1));
		A.push_back(make_pair(1,3));
		A.push_back(make_pair(3,1));
		A.push_back(make_pair(3,2));
		cout<<canFinish(4,A)<<endl;
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
