#include<iostream>
#include<string>
#include<vector>
#include <cctype>
#include<algorithm>
using namespace std ;
class Solution {
public:
    int minimumTotal(vector<vector<int> > &triangle) {
        int size=triangle.size();
        for(int i=1;i<size;i++)
        {
            for(int j=0;j<i+1;j++)
            {
                if(j==0)
                    triangle[i][j]+=triangle[i-1][j];
                else if(j==i)
                    triangle[i][j]+=triangle[i-1][j-1];
                else
                    triangle[i][j]=min(triangle[i][j]+triangle[i-1][j-1],triangle[i][j]+triangle[i-1][j]);
            }
        }
        return *min_element(triangle[size-1].begin(),triangle[size-1].end());
    }
    void print()
    {
		vector<vector<int > > cur;
		vector <int > X;
		X.push_back(10);
		cur.push_back(X);
		cout<<minimumTotal(cur)<<endl;
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
