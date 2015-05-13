#include<iostream>
#include<unordered_set>
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
#if 0
	vector<string> findRepeatedDnaSequences(string s) {
		vector<string> res;
		int i,loc;
		string foo,bar;
		int size=s.length();
		if(size<=10)
			return res;
		for(i=0;i+10<=size;i++){
			foo=s.substr(i,10);
			if(find(res.begin(),res.end(),foo)!=res.end())
				continue;
			loc=s.find(foo,i+1);
			if(loc>0){
				cout<<"foo: "<<foo<<" i: "<<i<<" loc "<<loc<<endl;
				res.push_back(foo);
				for(;s[i+10]==s[loc+10]&&i+10<=size&&loc+10<=size;i++,loc++){
					if(find(res.begin(),res.end(),s.substr(i+1,10))==res.end())
						res.push_back(s.substr(i+1,10));
				}
			}
		} 
		return res;
	}
#else
	
    vector<string> findRepeatedDnaSequences(string s) {
        vector<string> res;
		int i,foo_i;
		string foo,bar;
		unordered_set<int> A;
		int size=s.length();
		if(size<=10)
			return res;
		for(i=0;i+10<=size;i++){
			foo=s.substr(i,10);
			foo_i=str2num(foo);
			if(A.find(foo_i)==A.end()){
				A.insert(foo_i);
			}
			else{
				if(find(res.begin(),res.end(),foo)==res.end())
				res.push_back(foo);
			}
		}
	//	sort(res.begin(),res.end());
	//	res.erase(unique(res.begin(),res.end()),res.end());
		return res; 
    }
    int str2num(string A){
    	int i,res=0;
    	for(i=0;i<10;i++){
    		if(A[i]=='A')
    			res+=0;
    		else if(A[i]=='C')
    			res+=1;
    		else if(A[i]=='T')
    			res+=2;
    		else if(A[i]=='G')
    			res+=3;
    		res=res<<2;
		}
		return res;
	}
#endif
    void print()
    {
		vector<string> res;
		string A="AAAAACCCCCAAAAACCCCCCAAAAAGGGTTTAAAAAAAAAAAACCCCCCCCCCC";
		//string A="GATGGATACTGCATTCGAACCAGAGCCGGCTTTTGCGGGACTAGCATGAGGGACTTGGCTGTTGAGGCTGTACGAGGTCAGTCCTCCGGCAGTGCTATCGCAGGAATTTTTGCAACTCCACTGCTTATAATCCACCAAGTCCAGACTCAAAGCTCAACTCGGGGATCGCACGGTATGGTCACTGTCGCGCATGCAGTAATAGTCCAGACGAACGCACATTGGTCGTCCCCTGAGCCCGTGCCAGCCTAATACTTCTTATGCCTGCGTAAGTAGACTTTGCCAACGTAATCTCATCCTTATGCCAGATTATTAGTTCATTGAATGTCGGTCGCCGGCGCTCCCGCATTTCTTA";
		res=findRepeatedDnaSequences(A);
		int i;
		cout<<res.size()<<endl;
		for(i=0;i<res.size();i++){
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
