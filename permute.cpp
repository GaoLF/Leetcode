#include<iostream>
#include<string>
#include<vector>
#include <cctype>
#include<algorithm>
#include<math.h>
using namespace std ;
struct ListNode{
	int val;
	ListNode *next;
	ListNode(int x):val(x),next(NULL){}
};
class Solution {
public:
    vector<vector<int> > permute(vector<int> &num) {
        vector<vector<int> >res;
        vector<int>::iterator iter;
        vector<int> cur;
        trans(cur,res,num);
        return res;
    }
    int trans(vector<int> prex,vector<vector<int> > &res, vector<int> num)
    {
		//prex是前缀，res是最后的结果，num是除去当前一个数字之后的vector
		//开始情况：prex=空，res=空，num=[1,2,3]
		//然后判断num是否为空，空则将prex加入res
		//否则，prex分别等于[1][2][3],num分别删去[1][2][3],即分别[23][13][12] 
        vector<int>::iterator iter;
        if(!num.size())
        {
            res.push_back(prex);
            return 0;
        }
        for(iter=num.begin();iter!=num.end();iter++)
        {
			vector<int> curprex=prex;
            curprex.push_back(*iter);
            vector<int> curxx=num;
            num.erase(iter);
            trans(curprex,res,num);
            num=curxx;
        }
    }
    void print()
    {
		vector<vector <int> > x;
		vector<int> y;
		int XX[8]={1,2,3,4,5,6,7,8}; 
		y=vector<int>(XX,XX+7);
		x=permute(y);
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
