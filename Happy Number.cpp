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
    vector<int> flag;
    bool isHappy(int n) {
        int sum=0;
        int i;
        cout<<n<<endl;
        while(n>0){
            sum+=((n%10)*(n%10));
            n=n/10;
        }
        if(sum==1)
            return 1;
        for(i=0;i<flag.size();i++){
            if(flag[i]==sum)
                return 0;
        }
                    
        flag.push_back(sum);
        return isHappy(sum);
            
    }

    void print()
    {
    	cout<<isHappy(2)<<endl;
		cout<<isHappy(81)<<endl; 

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
