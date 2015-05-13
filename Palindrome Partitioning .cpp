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
    vector<vector<string> > partition(string s) {
    	int size=s.length();
        vector<vector<vector<string> > > res;
        vector<vector<string> > bar;
		vector<string> cur;
		string foo;
		int i,j,m;
		
		cur.push_back(s.substr(0,1));
		bar.push_back(cur);
		res.push_back(bar);
		for(i=1;i<size;i++){
			bar.clear();
			res.push_back(bar);
			for(j=0;j<=i;j++){
				foo=s.substr(j,i-j+1);
			//	cout<<foo<<endl;
				if(check(foo)){
				//	cout<<"!"<<foo<<" "<<j<<endl;
					if(!j){
						cur.clear();
						cur.push_back(foo);
						res[i].push_back(cur);
					}
					else{
						bar=res[j-1];
						for(m=0;m<bar.size();m++){
							bar[m].push_back(foo);
							res[i].push_back(bar[m]);
						}
					}
				}
			}
			
		}
		return res[size-1];
    }
    bool check(string A){
    	int size=A.length();
    	for(int i=0;i<size;i++)
    		if(A[i]!=A[size-i-1])
    			return 0;
		return 1;
	}
    void print()
    {
    	string A="aabba";
    	vector<vector<string> > B;
    	B=partition(A);
    	int i,j;
    	for(i=0;i<B.size();i++){
    		for(j=0;j<B[i].size();j++)
    			cout<<B[i][j]<<" ";
    		cout<<endl;
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
