#include<iostream>
#include<string>
#include<vector>
#include <cctype>
#include<algorithm>
#include<math.h>
using namespace std ;
class Solution {
public:
    int trailingZeroes(int n) {
		return n/5+check(n);
    }
    int check(int n)
    {
		if(n<25)
			return 0;
		int res=1;
		int cur,count,cur2;
		cur=(int)(log(n)/log(5));
		cur2=(int)pow(5,cur);
		count=n/cur2;
		for(int i=2;i<cur;i++)
			res=res*5+1;
		res*=count;
		cout<<res<<endl;
		return res+check(n%cur2);

	}
    void print()
    {
		vector<vector <int> > x;
		vector<int> y;
		y.push_back(1);
		y.push_back(2);
		y.push_back(3);
		y.push_back(4);
		//x.push_back(y);
		int P[13]={0,1,0,2,1,0,1,3,2,1,2,1};
		int Q[4]={4,2,3};
		int M[11]={5,5,1,7,1,1,5,2,7,6};
		cout<<endl<<endl;
		cout<<trailingZeroes(625)<<endl;
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
