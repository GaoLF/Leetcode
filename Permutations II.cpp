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
    vector<vector<int> > permuteUnique(vector<int> &num) {
		int i,j,m,length=num.size();
		int size,foo;
		vector<vector<int> >res;
		vector<int> temp;
	//	res.push_back(temp);
		
		if(!length)
			return res;
		sort(num.begin(),num.end());
		for(i=0;i<length;i++){
			foo=num[i];
			size=res.size();
			vector<vector<int> >::iterator iter;
			if(i==0){
				temp.push_back(foo);
				res.push_back(temp);
				continue;
			}		
			
			for(j=0,iter=res.begin();j<size;j++){
				int bar=res[j].size();
				//cout<<foo<<" "<<size<<" "<<bar<<endl;
				for(m=0;m<=bar;m++){
					temp=vector<int>(res[j]);
					temp.insert(temp.begin()+m,foo);
					res.push_back(temp);	
				}
						
				/*	for(int i=0;i<res.size();i++)
					{
						for(int j=0;j<res[i].size();j++)
							cout<<res[i][j]<<" ";
							cout<<endl;
					}
					cout<<endl;*/
			//	res.erase(res.begin()+j);		
						
				
			}
			res.erase(res.begin(),res.begin()+size);
			sort(res.begin(),res.end());
			res.erase(unique(res.begin(),res.end()),res.end());
		}
		return res;
    }

    void print()
    {		
		vector<vector <int> > x;
		vector<int> y;
		int XX[8]={1,1,0,0,1,-1,-1,1}; 
		y=vector<int>(XX,XX+3);
		x=permuteUnique(y);
		for(int i=0;i<x.size();i++)
		{
			for(int j=0;j<x[i].size();j++)
				cout<<x[i][j]<<" ";
			cout<<endl;
		}
		cout<<endl;
		//cout<<x.size()<<endl;

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
