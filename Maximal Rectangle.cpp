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
    int maximalRectangle(vector<vector<char>>& matrix) {
        int i,j,res=0;
        int size1=matrix.size();
        if(!size1)
        	return 0;
        int size2=matrix[0].size();

    	for(i=0;i<size1;i++){
    		for(j=0;j<size2;j++){
    			if(matrix[i][j]=='1'){
    				res=max(res,check(matrix,i,j,size1,size2));
				}
			}
		}
		return res;
    }
    int check(vector<vector<char> >&m,int row,int col,int size1,int size2){
		int area=0;
		int i,j,foo,bar;
	//	cout<<row<<" "<<col<<" "<<size1<<" "<<size2<<endl;
		for(i=0,foo=size2-col;i+row<size1&&m[i+row][col]!='0';i++){
			for(j=0;j<foo;j++){
				if(m[i+row][j+col]=='0'){
					break;
				}
			//	cout<<j<<"@@@"<<endl;
			}
			if(j==foo)
				area=max(area,foo*(i+1));
			else{
				foo=j;
				area=max(area,foo*(i+1));
			}
	//		cout<<j<<" "<<foo<<" "<<area<<endl; 
		}
	//	cout<<area<<"@@"<<endl;
		return area;
	}

    void print()
    {
    	vector<vector<char> > X,Y;
    	vector<char> A,B,C,D,E;
    	
    	A.push_back('1');
    	A.push_back('1');
    	A.push_back('1');
    	A.push_back('1');
    	A.push_back('1');
    	A.push_back('1');
    	A.push_back('1');
    	A.push_back('1');
    	//cout<<"~~~~~~~~~~~~~~"<<maximalRectangle(X)<<endl;
		X.push_back(A);
		cout<<"~~~~~~~~~~~~~~"<<maximalRectangle(X)<<endl;
		A.clear();
    	B.push_back('1');
    	B.push_back('1');
    	B.push_back('1');
    	B.push_back('1');
    	B.push_back('1');
    	B.push_back('1');
    	B.push_back('1');
    	B.push_back('0');
		X.push_back(B);
		cout<<"~~~~~~~~~~~~~~"<<maximalRectangle(X)<<endl;
		A.clear();
    	A.push_back('1');
    	A.push_back('1');
    	A.push_back('1');
    	A.push_back('1');
    	A.push_back('1');
    	A.push_back('1');
    	A.push_back('1');
    	A.push_back('0');
		X.push_back(A);
		cout<<"~~~~~~~~~~~~~~"<<maximalRectangle(X)<<endl;
		A.clear();
    	A.push_back('1');
    	A.push_back('1');
    	A.push_back('1');
    	A.push_back('1');
    	A.push_back('1');
    	A.push_back('0');
    	A.push_back('0');
    	A.push_back('0');
		X.push_back(A);	
		cout<<"~~~~~~~~~~~~~~"<<maximalRectangle(X)<<endl;
		A.clear();
    	A.push_back('0');
    	A.push_back('1');
    	A.push_back('1');
    	A.push_back('1');
    	A.push_back('1');
    	A.push_back('0');
    	A.push_back('0');
    	A.push_back('0');
		X.push_back(A);
		
	    cout<<"~~~~~~~~~~~~~~"<<maximalRectangle(X)<<endl;
		
		
		C.push_back('0');
		C.push_back('1');
		Y.push_back(C);
		Y.push_back(C);
		cout<<maximalRectangle(Y)<<endl;
		
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
