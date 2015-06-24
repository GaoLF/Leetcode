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
    int strStr(string haystack, string needle) {
        int i,j,h_size,n_size,flag;
        h_size=haystack.size();
        n_size=needle.size();
        if(!n_size)
            return 0;
        if(!h_size)
            return -1;
            
        
		vector<int> next(n_size,0);
		next[0]=-1;
        for(i=1,j=0;i<n_size;i++){
			if(needle[i]==needle[j]){
				
				next[i]=j;
				j++;
			}
			else if(needle[i]!=needle[j]){
				next[i]=-1;
				j=0;
			}
		}
		//for(i=0;i<next.size();i++)
		//	cout<<next[i]<<" ";
	//	cout<<endl;
		for(i=0,j=0;i<h_size;){
			if(haystack[i]==needle[j]){
				if(j==n_size-1)
					return i-j;
				else{
					i++;
					j++;
				}
				//cout<<haystack[i]<<" "<<i<<" "<<j<<endl;
			}
			else{
				if(j==0||next[j-1]==-1){
					j=0;
					if(haystack[i]==needle[0]){
					//	j++;
					}
					else
						i++;		
				}
				else{
					j=next[j-1]+1;
				}
			}
		}
		return -1;
    }

    void print()
    {
		char A[14]="AVVVVAVVVCAVC";
		char B[3]="VC";
		cout<<strStr("bbababbaa", "bbabba")<<endl;
		cout<<strStr("babba", "bbb")<<endl;
		cout<<strStr("mississippi", "issip")<<endl;
		cout<<strStr("mississippi", "pi")<<endl;
	    cout<<strStr(A,B)<<endl; 
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
