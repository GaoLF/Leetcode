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
    vector<int> findSubstring(string s, vector<string>& words) {
        unordered_map<string,int> map;
        unordered_map<string,int> temp;
        int i,j,size=words.size();
        int len=s.length();
        vector<int> res;
        
		if(!len||(!size))
			return res;
		int wlen=words[0].length();
		if(len<(wlen*size))
			return res;
        for(i=0;i<size;i++){
        	auto iter=map.find(words[i]);
        	if(iter==map.end())
        		map.insert(make_pair(words[i],1));
        	else
        		iter->second++;
        		
		}
		for(i=0;i<(len-wlen*size+1);i++){
			temp=map;
			for(j=0;j<size*wlen;j+=wlen){
				string foo=s.substr(j+i,wlen);
			//	cout<<foo<<endl;
				auto iter=temp.find(foo);
				if(iter==temp.end())
					break;
				else{
					iter->second--;
					if(iter->second<0)
						break;
				}
			}
		//	cout<<j<<" "<<i<<" "<<size*wlen<<endl;
			if(j>=size*wlen){
				res.push_back(i);
		//		cout<<j<<" "<<i<<" "<<size*wlen<<endl;
			}
				
		}
		return res;
    }

    void print()
    {
		vector<string> A;
		A.push_back("fooo");
		A.push_back("barr");
		A.push_back("wing");
		A.push_back("ding");
		A.push_back("wing");
		vector<int> res;
		res=findSubstring("lingmindraboofooowingdingbarrwingmonkeypoundcake",A);
		for(int i=0;i<res.size();i++){
			cout<<res[i]<<endl;
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
