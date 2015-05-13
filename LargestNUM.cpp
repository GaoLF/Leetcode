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
    string largestNumber(vector<int> &num) {
        vector<string> cur_str;
        string res;
        int i,j,size=num.size();
        char B[256]="";
        for(i=0;i<size;i++){
            sprintf(B,"%d",num[i]);
            cur_str.push_back(B);
        } 
        sort(cur_str.begin(),cur_str.end());
        for(j=0;j<size;j++)
        for(i=0;i<size;i++){
            if(i<size-1&&(cur_str[i]+cur_str[i+1])>(cur_str[i+1]+cur_str[i]))
                swap(cur_str[i],cur_str[i+1]);       
        }
        for(i=size-1;i>=0;i--){
            res+=cur_str[i];
        }
        if(size&&cur_str[size-1]=="0")
            res="0";
        return res;
    }
    void print(){
        vector<int> A;
        A.push_back(74);
        A.push_back(21);
        A.push_back(33);
        A.push_back(51);
        A.push_back(77);
        A.push_back(51);
        A.push_back(90);
        A.push_back(60);
        A.push_back(5);
        A.push_back(56);
        cout<<largestNumber(A)<<endl;
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
