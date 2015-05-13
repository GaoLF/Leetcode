//
//  searchrange.cpp
//  
//
//  Created by Gao on 15-2-16.
//
//

#include <stdio.h>
#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    void test(){
    	string a="abcdefg";
		string b,c,d;
		b=string(a,3,4);
	//	c=string(a,3);
		d=string(a,0,3);
		d='0'*3;
		c=b+d;
		string e(a,0,3);
		int x=4;
		x=4<<3;
		b="dcba";
		sort(b.begin(),b.end());
		cout<<b<<endl;
//		cout<<b<<endl;
//		cout<<c<<endl;
//		cout<<(int)'0'<<endl;
//		cout<<(int)'1'<<endl;
//		cout<<d<<endl;
//		cout<<e<<endl;
	}
    
};
int main(){
    Solution C;
    C.test();
}








