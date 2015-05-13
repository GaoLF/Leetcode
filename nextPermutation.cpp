#include<iostream>
#include<string>
#include<vector>
#include <cctype>
#include<algorithm>
#include<math.h>
using namespace std ;
class Solution {
public:
	//这个题的意思是找字典顺序的下一个数
	//比如 1/2/3/4
	//选2341的下一个，则为2413，即选bcda后边比其大最少的数
	// 
    void nextPermutation(vector<int> &num) {
        //num.size();
        int curnum;
        vector<int>::iterator iter,curiter; 
        if(num.size()>1)
		{
        for(iter=num.end()-1;iter!=num.begin();iter--)
        {
			if(*iter>*(iter-1))
				break;
		}
		if(iter!=num.begin())//i!=0
		{
			for(curiter=iter;curiter!=num.end();curiter++)
			{
				if(*curiter<=*(iter-1))
					break;
			}	
//			if(curiter!=num.end())
			{
				swap(*(iter-1),*(curiter-1));
			}
//			else
//				 swap(*(iter-1),*(curiter));
		//	num.sort(iter,num.end());
		} 
		sort(iter,num.end());
		}
    }

    void print()
    {
		vector<vector <int> > x;
		vector<int> y;
		y.push_back(1);
		y.push_back(5);
		y.push_back(1);
//		y.push_back(2);
		//x.push_back(y);
		int P[13]={0,1,0,2,1,0,1,3,2,1,2,1};
		int Q[4]={4,2,3};
		int M[11]={5,5,1,7,1,1,5,2,7,6};
//		isValid("[({(())}[()])]");
		nextPermutation(y);
		for(int i=0;i<y.size();i++)
			cout<<y[i]<<"  ";
		cout<<endl;
		//cout<<trailingZeroes(625)<<endl;
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
