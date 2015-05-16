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

	//¸øµÄ²âÊÔÀý×ÓÌ«¿Óµù

    int candy(vector<int>& ratings) {
    	int i,j,m,size=ratings.size();
    	int res=0,foo,temp;
        vector<int> can(size,1);
		for(i=1;i<size;i++){
			if(ratings[i]>ratings[i-1])
				can[i]=can[i-1]+1;
			else if(ratings[i]<ratings[i-1]){
				if(can[i-1]<=1){
					for(foo=0;i<size;i++){
						if(ratings[i]<ratings[i-1])
							can[i]=can[i-1]-1;
					//	else if(ratings[i]==ratings[i-1])
					//		can[i]=can[i-1];
						else
							break;
						foo++;
					}
					for(m=i-1;m>=0;m--){				
						temp=can[m];
						can[m]+=foo;
						if(m){
							if(can[m-1]-temp>foo)
								break;
							if(can[m-1]<temp)
								break;
							if(ratings[m-1]==ratings[m])
								break;
							//if(can[m-1]!=temp)
								foo-=(can[m-1]-temp-1);
						}
					
					}
					i--;
				}	
			}
	//		else
	//			can[i]=can[i-1];
		} 
		for(i=0;i<size;i++){
			res+=can[i];
			cout<<can[i]<<endl;
		}
		return res;
    }

    void print()
    {
		vector<int> A;	
		A.push_back(1);
		A.push_back(2);
		A.push_back(2);
		A.push_back(5);
		A.push_back(5);
		A.push_back(4);
		A.push_back(3);
		A.push_back(2);
		A.push_back(1);
		A.push_back(0);
		A.push_back(2);
		A.push_back(1);
		A.push_back(0);
		cout<<candy(A)<<endl;
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
