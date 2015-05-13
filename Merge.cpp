#include<iostream>
#include<string>
#include<vector>
#include <cctype>
#include<algorithm>
using namespace std ;
class Solution {
public:
    int removeDuplicates(int A[], int n) {
        int i,j,length;
        length=n;
        if(!n||n==1)
            return n;
        for(i=0,j=0;i<n-1;i++)
        {
            if(A[i+1]==A[i])
            {

                length--;
            }
            else
            {
				j++;
				A[j]=A[i+1];
			}
        }
        return length;
    }
    void print()
    {
		int A[7]={0};
		int B[3]={0};
		int i;
		A[0]=1;
		A[1]=2;
		A[2]=4;
		A[3]=4;
		A[4]=5;
		A[5]=5;
		A[6]=6;
		B[0]=2;
		B[1]=5;
		B[2]=6;
		int n=removeDuplicates(A,7);
		for(i=0;i<n;i++)
			cout<<A[i]<<endl;
			cout<<n<<endl;
	}
	bool abc()
	{
		abc();
		cout<<"a"<<endl;
		return 0;
	}
	 
};
struct list{
	int a;
	list* next;
};
int main()
{
	Solution test;
	list *x,*y;
	x=(list*)malloc(sizeof(list));
	y=(list*)malloc(sizeof(list));
	
//	char a[5]="abcd";
	char a[5]="";
	if(!a)
		cout<<"ddd"<<endl;
	cout<<"->"<<*a<<"<-"<<endl;
	cout<<endl;
	test.abc();
//	if(a)
//	cout<<test.Low("A man, a plan, a canal: Panama")<<endl;
//	test.print();
//	cout<<atoi("2147483648")<<endl;
	system("pause");
}
