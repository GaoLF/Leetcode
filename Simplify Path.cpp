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
    string simplifyPath(string path) {
        vector<string> cur;
		int i,count,size;
		string foo,res="";
		vector<string>::iterator iter,curiter;
		for(i=0;i<path.length();){
			size=0;
			while(path[i+size]!='/'&&((i+size)<path.length())){
				size++;
			}
			if(size){
				foo=path.substr(i,size);
				cur.push_back(foo);
			}
			i+=(size+1);
		}
		for(iter=cur.begin();iter!=cur.end()&&cur.size();){
			if(*iter=="."){
				if(iter==cur.begin()){
					cur.erase(iter);
					iter=cur.begin();
				}
				else
					iter=cur.erase(iter);
			}
			else if(*iter==".."){
				if(iter==cur.begin()){
					cur.erase(iter);
					iter=cur.begin();
				}
				else{
					iter=cur.erase(iter)-1;	
					if(cur.size()){
						if(iter==cur.begin()){
							cur.erase(iter);
							iter=cur.begin();
						}
						else
							iter=cur.erase(iter)-1;
					}
				}
			}
			else{
				iter++;
			}	

		}
		if(cur.size()==0)
			return "/";
		for(iter=cur.begin();iter!=cur.end();iter++){
			res+=("/"+*iter);
		}
		return res;
    }
    void print()
    {
		cout<<simplifyPath("/../")<<endl;
		cout<<simplifyPath("/home/foo/../bar/")<<endl;
		cout<<simplifyPath("/a/./b/../../c/")<<endl;
		cout<<simplifyPath("/home/of/foo/../../bar/../../is/./here/.")<<endl;
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
