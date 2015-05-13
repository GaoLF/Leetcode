#include<iostream>
#include<string>
#include<vector>
#include <cctype>
#include<algorithm>
using namespace std ;
class Solution {
public:
	int maxProfit(vector<int> &prices) {
		if(prices.size()<2)
			return 0;
		int cur=0;
		int i,maxvalue;
		for(i=prices.size()-1,maxvalue=prices[i];i>=0;i--)
		{
			if(prices[i]>maxvalue)
				maxvalue=prices[i];
			else
				cur=max(cur,maxvalue-prices[i]);
		} 
		return cur;
	}
	
//�Ҹо����������ȷ�ˣ�������֤��ʱ��˵��
//Input:	[2,1,2,0,1]
//Output:	2
//Expected:	1 
//�ѵ�������2ô������������������ô�� 
//�����Ŀ��ȫ����ˣ���Ҫ��������������������������������ۻ������� 
/* 
	int maxProfit(vector<int> &prices) {
		vector<int>::iterator curiter,miniter;
		int profit=0;
		for(curiter=prices.end()-1;prices.size()>1;)
		{
			if(curiter==prices.end())
				curiter=prices.end()-1;
			if(curiter==prices.begin())
			{	
				//curiter=prices.erase(curiter);
				break;
			}
			if(*(curiter-1)<*curiter)
			{
				for(miniter=curiter-1;miniter>prices.begin()&&(*(miniter-1)<*miniter);miniter--);
				profit+=(*curiter-*miniter);	
				if(curiter==prices.end()-1)
				{
					prices.erase(curiter);
					curiter=prices.end()-1;
				}
				else
					curiter=prices.erase(curiter);	
				prices.erase(miniter);
			}
			else 
				curiter--;
				
		} 
		return profit;
	}
	*/
	/*Time Limit Exceeded:��vector������С�ģ�Ȼ�����С��λ�õ���������ֵ��profit���϶���֮�ɾ�����������������㡣
	��������ǲ��Եģ�����˵1��8��3��9 
	int maxProfit(vector<int> &prices) {	
		vector<int>::iterator miniter,maxiter;
		int profit=0;
		int minvalue=0;
		int maxvalue=0;
		while(prices.size()>1)
		{
			miniter=min_element(prices.begin(),prices.end());
			minvalue=*miniter;
			prices.erase(miniter);
			if(miniter<prices.end())
			{
				maxiter=max_element(miniter,prices.end());
				maxvalue=*maxiter;
				profit+=(maxvalue-minvalue);
				prices.erase(maxiter);
			}
			
		}
		return profit;
	} 
	*/ 
	void print()
	{
		vector<int > x;
		x.push_back(2);
		x.push_back(1);
		x.push_back(2);
		x.push_back(0);
		x.push_back(1);
//		x.push_back(7);

//		x.push_back(9);
		cout<<maxProfit(x)<<endl;
//		cout<<x.size()<<endl;
//		x.erase(x.begin());
//		cout<<x.size()<<endl;
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
