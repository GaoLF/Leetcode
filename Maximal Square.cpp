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
    int maximalSquare(vector<vector<char> >& matrix) {
        int cur[100][100];
        int i,j,res=0;
        int row=matrix.size();
        if(!row)
        	return 0;
        int col=matrix[0].size();
		for(i=0;i<row;i++)
			for(j=0;j<100;j++)
				cur[i][j]=0;
		for(i=0;i<row;i++){
			for(j=0;j<col;j++){
				if(matrix[i][j]=='1'){
                    if(cur[i][j]==-1)
                        continue;
					res=max(res,check(matrix,cur,i,j,row,col));
				//	cout<<res<<endl;
				}
			} 
		}
		return res;
    }
	int check(vector<vector<char> >& matrix,int cur[][100],int i,int j,int row,int col){
		int x,y,iter;
		int temp=cur[i][j];
		for(iter=temp+1;i+iter<row;iter++){
			if((i+iter>=row)||(j+iter>=col))
				break;
			for(x=i;x<=i+iter;x++)
				if(matrix[x][j+iter]=='0'){
                    for(int m=i;m<=x;m++)
                        for(int n=j;n<=(j+iter);n++)
                            cur[m][n]=-1;
                    break;
                }
					
			for(y=j;y<=j+iter;y++)
				if(matrix[i+iter][y]=='0'){
				    for(int m=i;m<=(i+iter);m++)
				        for(int n=j;n<=y;n++)
				            cur[m][n]=-1;
                    break;
                }
			if(x<=(i+iter)||y<=(j+iter))
				break;
		}
	//	cout<<i<<" "<<j<<" "<<iter<<" "<<temp<<endl; 
		
		if(iter-1>temp){
			for(x=i+1;x<(i+iter);x++)
				for(y=j+1;y<(j+iter);y++){
					cur[x][y]=iter-(x-i+y-j);
				}
            for(x=i;x<(i+iter);x++){
                cur[x][j]=-1;
                cur[i][x]=-1;
            }	
		}
	
		return iter;
	}
	
    void print()
    {//0110111111111111110","1011111111111111111","1101111111110111111","1111111111111011111","1111111111111101111","1110111011111111101","1011111111111101111","1111111111111110110","","1101111111011111111","1111111110111111111","0110111011111111111","1111011111111101111","1111111111111111111","1111111111111111111","1111111111111111101","1111111101101101111","1111110111111110111
    	vector<vector<char> >temp;
    	char A[20]="0110111111111111110";
		vector<char> cur(A,A+20);
		temp.push_back(cur);
    	char A1[20]="1011111111111111111";
		vector<char> cur1(A1,A1+20);
		temp.push_back(cur1);
    	char A2[20]="1101111111110111111";
		vector<char> cur2(A2,A2+20);
		temp.push_back(cur2);
    	char A3[20]="1111111111111011111";
		vector<char> cur3(A3,A3+20);
		temp.push_back(cur3);
    	char A4[20]="1111111111111101111";
		vector<char> cur4(A4,A4+20);
		temp.push_back(cur4);
    	char A5[20]="1110111011111111101";
		vector<char> cur5(A5,A5+20);
		temp.push_back(cur5);
    	char A6[20]="1011111111111101111";
		vector<char> cur6(A6,A6+20);
		temp.push_back(cur6);
    	char A7[20]="1111111111111110110";
		vector<char> cur7(A7,A7+20);
		temp.push_back(cur7);
    	char A9[20]="0011111111111110111";
		vector<char> cur9(A9,A9+20);
		temp.push_back(cur9);
    	char Aa[20]="1111111110111111111";
		vector<char> cura(Aa,Aa+20);
		temp.push_back(cura);
    	char Ab[20]="0110111011111111111";
		vector<char> curb(Ab,Ab+20);
		temp.push_back(curb);
    	char Ac[20]="1111011111111101111";
		vector<char> curc(Ac,Ac+20);
		temp.push_back(curc);
    	char Ad[20]="1111111111111111111";
		vector<char> curd(Ad,Ad+20);
		temp.push_back(curd);
    	char Ae[20]="1111111111111111111";
		vector<char> cure(Ae,Ae+20);
		temp.push_back(cure);
    	char Af[20]="1111111111111111101";
		vector<char> curf(Af,Af+20);
		temp.push_back(curf);
    	char Ag[20]="1111111101101101111";
		vector<char> curg(Ag,Ag+20);
		temp.push_back(curg);
		char Ah[20]="1111110111111110111";
		vector<char> curh(Ah,Ah+20);
		temp.push_back(curh);
    	
		//temp.push_back(A);
		//temp.push_back(B);
	//	temp.push_back(C);
	//temp.push_back(D);
		for(int i=0;i<temp.size();i++){
			for(int j=0;j<temp[i].size();j++)
				cout<<temp[i][j]<<" ";
			cout<<endl;
		}
		
    	cout<<maximalSquare(temp)<<endl;

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
