#include<iostream>
#include<string>
#include<vector>
#include <cctype>
#include<algorithm>
#include<math.h>
using namespace std ;
class Solution {
public:
    vector<vector<int> > combine(int n, int k) {
        vector<vector<int> > res;
        vector<int> cur;
        trans(k,n,cur,res);
        for(int i=0;i<res.size();i++)
            sort(res[i].begin(),res[i].end());
        return res;
    }
    int trans(int n,int k,vector<int> cur,vector<vector<int> >&res)
    {
		//˼·���ǣ�����˵����n=5,k=3
        //�����ж�n==k������һ���Լ���cur�����ж�n==1�����ڷֱ�ÿһ���ӽ�ȥ�������������ζ��������cur push��res
        //�����������������������������������trans(4,3)��˼Ϊ������5��1-4����3����
        //��5����cur��trans(5,2)����˼Ϊ����5��Ȼ����1-4��������
        int i,j;
        if(n==k)
        {
            for(i=0;i<n;i++)
                cur.push_back(i+1);
            res.push_back(cur);
            return 0;
        }
        if(n==1)
        {
			vector<int> x;
            for(i=0;i<k;i++)
            {	
                x=cur;
                x.push_back(i+1);
                res.push_back(x);
            }
            return 0;
        }
        trans(n,k-1,cur,res);
        cur.push_back(k);
        trans(n-1,k-1,cur,res);
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
		x=combine(4,2);
		cout<<endl<<endl;
		for(int i=0;i<x.size();i++)
		{
			for(int j=0;j<x[0].size();j++)
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
