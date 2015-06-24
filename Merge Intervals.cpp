#include<iostream>
#include<string>
#include<vector>
#include <cctype>
#include<algorithm>
#include<math.h>
using namespace std ;
 struct Interval {
     int start;
     int end;
     Interval() : start(0), end(0) {}
     Interval(int s, int e) : start(s), end(e) {}
 };
bool operator <(const Interval& A,const Interval& B){
	return A.start<B.start;
}
class Solution {
public:
    vector<Interval> merge(vector<Interval>& intervals) {
        sort(intervals.begin(),intervals.end());
        int i,j,size=intervals.size();
        vector<Interval> res;
		int begin,end;
		
		for(auto iter=intervals.begin();iter<intervals.end();){
			begin=iter->start;
			end=iter->end;
			auto temp=iter+1;
			for(;(temp)<intervals.end()&&((temp)->start<=end);temp++){
				if(temp->end>end)
					end=temp->end;
			}
			iter=temp;
			Interval foo(begin,end);
			res.push_back(foo);
		}
		return res;
    }
    void print()
    {
		Interval A(1,3);
		Interval B(2,6);
		Interval C(8,10);
		Interval D(15,28);
		vector<Interval> X,res;
		X.push_back(D);
		X.push_back(C);
		X.push_back(B);
		X.push_back(A);
		res=merge(X);
		//cout<<"!"<<endl;
		//cout<<res.size()<<endl;
		for(int i=0;i<res.size();i++){
			cout<<res[i].start<<" "<<res[i].end<<endl;
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
