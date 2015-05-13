#include<string>
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int main()
{
	string s("WelcomeToWebSite!");
	//cout<<s<<endl;transform(s.begin(),s.end(),s.begin(),tolower);//字母转小写
	//cout<<s<<endl;transform(s.begin(),s.end(),s.begin(),toupper);//字母转大写
	cout<<s<<endl;
	vector<int> b;
	
	std::vector<std::vector<int> > a;
    for(int i=0; i<5; ++i)
    {
    	a.push_back(b);
    	for(int j=0; j<5; ++j)
    	{
    		a[i].push_back(j);
      	}
    }
    cout<<a.size()<<endl;
	cout<<a[0].size()<<endl;
	cout<<a[0][0]<<endl;
	
	vector<vector<int> > A;
	A[0].push_back(1);
	A[1].push_back(2);
	cout<<A.size()<<endl;
	cout<<A[0].size()<<endl;
	cout<<A[0][0]<<endl;
	

}
