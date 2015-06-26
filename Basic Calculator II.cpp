#include<iostream>
#include<string>
#include<vector>
#include <cctype>
#include<algorithm>
#include<math.h>
#include<stack>
using namespace std ;
typedef struct ListNode{
	int val;
	ListNode * next;
} ListNode;
class Solution {
public:
    int calculate(string s) {
        vector<int> A;
        vector<int> op;
        int size=s.length();
        int i,j,res=0,oper=0,foo;
        
		for(i=0;i<size;i++){
			if(s[i]=='('){
				int flag=1;
				for(j=i+1;j<size;j++){
					if(s[j]=='(')
						flag++;
					if(s[j]==')')
						flag--;
					if(flag==0)
						break;
				}
				A.push_back(calculate(s.substr(i+1,j-i-1)));
				i=j;
			}
			else if(s[i]<='9'&&s[i]>='0'){
				foo=s[i]-'0';
				for(i++;i<size;i++){
					if(s[i]>'9'||s[i]<'0'){
						i--;
						break;
					}
					else
						foo=foo*10+(int)(s[i]-'0');
				}
				A.push_back(foo);
			}
			else if(s[i]=='+')
				op.push_back(1);
			else if(s[i]=='-')
				op.push_back(2);
			else if(s[i]!='*')
				op.push_back(3);
			else if(s[i]!='/')
				op.push_back(4);
		}
		vector<int > temp;
		//temp.push_back(A[0]);
		for(i=0;i<op.size();){
			if(op[i]==1||op[i]==2)
				i++;
			else if(op[i]=='3'){
				op.erase(op.begin()+i);
				A[i+1]=A[i]*A[i+1];
				A.erase(A.begin()+i);	
			}
			else if(op[i]=='4'){
				op.erase(op.begin()+i);
				A[i+1]=A[i]/A[i+1];
				A.erase(A.begin()+i);
			}
		}
		res=A[0];
		for(i=1;i<op.size();i++){
			if(op[i]=='1')
				res+=A[i];
			else
				res-=A[i];
		}
		cout<<res<<endl;
        return res;
    }

    void print()
    {
    	//cout<<calculate("")<<endl;
		//cout<<calculate("3+5 / 2")<<endl<<endl<<"!!!!!!!!!";
		//cout<<calculate("3+2*2")<<endl;
		//cout<<calculate("2-4-(8+2-6+(8+4-(1)+8-10))")<<endl;
		//cout<<calculate("2-1 + 2 ")<<endl;
		//cout<<calculate("(1+(4+5+2)-3)+(6+8)")<<endl;
	}
};
int main()
{
	Solution test;

//	cout<<test.Low("A man, a plan, a canal: Panama")<<endl;
	//test.print();
//	cout<<atoi("2147483648")<<endl;
	system("pause");
}
