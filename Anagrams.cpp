#include<iostream>
#include<string>
#include<vector>
#include <cctype>
#include<algorithm>
#include<math.h>
using namespace std ;

struct TreeLinkNode {
   int val;
   TreeLinkNode *left, *right, *next;
   TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
};
 
class Solution {
public:
	vector<string> anagrams(vector<string> &strs){
		vector<string> res,temp;
		int flag[100];
		int i,j,m,n,size=strs.size();
		string foo;
		
		if(!size)
			return res;
		for(i=0;i<100;i++)
			flag[i]=i;
		temp=strs;
		qsort2(temp,flag,0,size-1);
				
		for(i=0;i<size;){
			for(j=i+1;j<size;j++){
				if(temp[j].length()==temp[i].length());
				else
					break;
			}
			if(i+1!=j){
				for(m=i;m<j;m++)
					sort(temp[m].begin(),temp[m].end());
				qsort(temp,flag,i,j-1); 

				for(m=i;m<j;){
					foo=temp[m];
					for(n=m+1;n<j;n++){
						if(foo==temp[n]){
							res.push_back(strs[flag[n]]);
						}
						else
							break;
					}
					if(m+1!=n)
						res.push_back(strs[flag[m]]);
					m=n;			
				}
			}
			i=j;
		}
//		for(i=0;i<size;i++)
//			sort(temp[i].begin(),temp[i].end());
//		qsort(temp,flag,0,size-1); 
		
		
        return res;
    }
    void qsort(vector<string> &A,int flag[100],int left,int right){
    	if(left>=right)
    		return;
		int len_size=part(A,flag,left,right);
    	qsort(A,flag,left,len_size-1);
    	qsort(A,flag,len_size+1,right);
	}
	int part(vector<string>&A,int flag[100],int left,int right){
		int i,len_size=left;
		string temp=A[left];
		swap(A[left],A[right]);
		swap(flag[left],flag[right]);
		
		for(i=left;i<right;i++){
			if(A[i]<temp){
				swap(A[i],A[len_size]);
				swap(flag[i],flag[len_size]);
				len_size++;
			}
		}
		swap(A[len_size],A[right]);
		swap(flag[len_size],flag[right]);
		return len_size;
	}
	void qsort2(vector<string> &A,int flag[100],int left,int right){
    	if(left>=right)
    		return;
		int len_size=part2(A,flag,left,right);
    	qsort2(A,flag,left,len_size-1);
    	qsort2(A,flag,len_size+1,right);
	}
	int part2(vector<string>&A,int flag[100],int left,int right){
		int i,len_size=left;
		string temp=A[left];
		swap(A[left],A[right]);
		swap(flag[left],flag[right]);
		
		for(i=left;i<right;i++){
			if(A[i].length()<temp.length()){
				swap(A[i],A[len_size]);
				swap(flag[i],flag[len_size]);
				len_size++;
			}
		}
		swap(A[len_size],A[right]);
		swap(flag[len_size],flag[right]);
		return len_size;
	}
    void print()
    {
		vector<string> A,B;
		A.push_back("abcde");
		A.push_back("abcd");
		A.push_back("bacd");
		A.push_back("acbd");
		A.push_back("ed");
		A.push_back("abc");
		A.push_back("bcde");
		A.push_back("bde");
		A.push_back("cde");
		A.push_back("de");
		B=anagrams(A);
		for(int i=0;i<B.size();i++)
			cout<<B[i]<<" ";
		cout<<endl;
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
