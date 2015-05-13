//
//  searchrange.cpp
//  
//
//  Created by Gao on 15-2-16.
//
//

#include <stdio.h>
#include <iostream>
#include <vector>
#include <string>
using namespace std;
struct Interval{
	int start,end;
	Interval():start(0),end(0){}
	Interval(int s,int e):start(s),end(e){}
};
class Solution {
public:
    vector<Interval> insert(vector<Interval> &intervals,Interval newInterval){ 
        int i;
        int size=intervals.size();
        vector<Interval>::iterator iter;
        int insert_start=newInterval.start;
        int insert_end=newInterval.end;
        vector<Interval> node;
        if(!size||(intervals.begin()->start>insert_end)||(intervals.end()<insert_start)){
            intervals.push_back(newInterval);
            break;
        }
        for(i=0;iter->start>)
    }
    /*
  vector<Interval> insert(vector<Interval> &intervals,Interval newInterval){ 
		int newstart,newend,insert_start,insert_end;
		newstart=insert_start=newInterval.start;
		newend=insert_end=newInterval.end;
		Interval cur_inter;
		vector<Interval>::iterator iter;
		for(iter=intervals.begin();iter!=intervals.end();){
			if(iter->start>insert_start){
				if(iter->end<insert_end){//iter in the range of insert
					newstart=insert_start;
					intervals.erase(iter);
				}
				else if(iter->start<insert_end){//iter's start>insert's
					newend=iter->end;          //iter's end> insert's
					intervals.erase(iter);
				}
				else if(iter->start>insert_end){
					cur_inter.start=newstart;
					cur_inter.end=newend;
					intervals.insert(iter,cur_inter);
					break;
				}
			}
			else if(iter->start<insert_start&&(iter->end>insert_start)){
				if(iter->end>=insert_end){
					newstart=iter->start;
					newend=iter->end;
					intervals.erase(iter);
				}
				else{
					newstart=iter->start;//iter's start< insert's           
					intervals.erase(iter);
				}
			}
			else
				iter++;
		}
        return intervals;
    }
    */
    void test(){
        int A[10]={1,2,3,4,5,6,7,8,9,9};
        vector<Interval> B;
		Interval C(1,2);
		Interval D(3,5);
		Interval E(6,7);
		Interval F(8,10);
		Interval G(12,16);
		Interval H(4,9);
		B.push_back(C);
		B.push_back(D);
		B.push_back(E);
		B.push_back(F);
		B.push_back(G);
		B=insert(B,H);
		for(int i=0;i<B.size();i++)
			cout<<B[i].start<<"  "<<B[i].end<<endl;
    }
};
int main(){
    Solution C;
    C.test();
}








