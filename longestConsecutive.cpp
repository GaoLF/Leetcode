#include<iostream>
#include<string>
#include<vector>
#include <cctype>
#include<algorithm>
#include<math.h>
#include<unordered_map>
using namespace std ;
typedef struct ListNode{
	int val;
	ListNode * next;
} ListNode;
class Solution {
public:
    int longestConsecutive(vector<int> &num) {
		unordered_map<int,int> map;
		unordered_map<int,int>::iterator iter,temp_iter;
		int i,j,m,res=1,temp;
		if(!num.size())
			return 0;
		for(m=0;m<num.size();m++){
			temp=num[m];
			map.insert(make_pair(temp,0)); 
		}
		for(iter=map.begin();iter!=map.end();iter++){
		//	cout<<"!"<<iter->first<<endl; 
			int size=map.size();
			int foo,bar;
			foo=iter->first;
			bar=iter->second;
			
		
			if(bar){
			//	cout<<iter->first<<" "<<iter->second<<"~"<<endl;
				continue;
			}
	
			for(i=1;i-1<size;i++){
				temp_iter=map.find(foo+i);
			//	cout<<"!!"<<foo+i<<endl;
				if(temp_iter!=map.end()){
					bar=temp_iter->second;
					if(bar){
						for(j=0;j<i;j++){
							temp_iter=map.find(foo+j);
							temp_iter->second=i-j+bar;
						}
						break;
					}	
				}
				else{
					for(j=0;j<i;j++){
						temp_iter=map.find(foo+j);
						temp_iter->second=(i-j);
					}
					break;
				}
			}
			res=max(iter->second,res);
//			cout<<iter->first<<" "<<iter->second<<"~"<<endl;
		}
		return res;
    }

    void print()
    {
    	vector<int> A;
    	vector<int> B;
    	A.push_back(3);
    	A.push_back(2);
    	A.push_back(1);
    //	cout<<longestConsecutive(A)<<endl;
    //	A.push_back(3);
    	cout<<longestConsecutive(A)<<endl;
    	A.push_back(6);
    	cout<<longestConsecutive(A)<<endl;
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
