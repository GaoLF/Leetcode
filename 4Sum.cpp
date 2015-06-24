#include<iostream>
#include<string>
#include<vector>
#include <cctype>
#include<algorithm>
#include<math.h>
#include<unordered_map>
using namespace std ;
typedef struct ListNode{
	int val;
	ListNode * next;
} ListNode;
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int> > res;
        int sum_2num;
        int i,j;
        unordered_map<int,vector<int>> map;
        int size=nums.size();
        vector<int> encode;
        
		for(i=0;i<size;i++){
			for(j=i+1;j<size;j++){
				//cout<<"!"<<endl;
				sum_2num=nums[i]+nums[j];
				auto iter_temp=map.find(sum_2num);
				if(iter_temp==map.end()){
					vector<int> vec_temp;
					vec_temp.push_back((i<<8)+j);
					//cout<<i<<" "<<j<<" "<<((i<<5)+j)<<"~~~"<<endl;
					map.insert(make_pair(sum_2num,vec_temp));
				}
				else{
					iter_temp->second.push_back((i<<8)+j);
					cout<<sum_2num<<endl;
				}
					
			}
		}
		for(auto iter=map.begin();iter!=map.end();){
			auto iter_temp=map.find(target-iter->first);
			if(iter_temp!=map.end()){
			//	cout<<iter_temp->first<<":"<<iter->first<<"~~"<<endl;
			
				for(i=0;i<iter->second.size();i++){
					for(j=0;j<iter_temp->second.size();j++){
					//	cout<<(iter->second[i])<<" "<<(iter_temp->second[j])<<" "<<(iter->second[i])<<10+(iter_temp->second[j])<<endl;
						int A=iter->second[i];
						int B=iter_temp->second[j];
						int C=A^B;
						int D=C&0xff;
						int E=(C&0xffff)>>8;
						int F=((A>>8)^B)&0xff;
						int G=((B>>8)^A)&0xff;
						if(D&&E&&F&&G){
							vector<int> temp;
							temp.push_back(nums[A>>8]);
							temp.push_back(nums[A&0xff]);
							temp.push_back(nums[B>>8]);
							temp.push_back(nums[B&0xff]);
							sort(temp.begin(),temp.end());
							res.push_back(temp);
						}
					}	
				}
			}
			map.erase(iter++);
		}
		sort(res.begin(),res.end());
		res.erase(unique(res.begin(),res.end()),res.end());
		return res;
    }

    void print()
    {
    	//int A[]={1,2,3,4,5,6,7,8,9,0,6,2,3,5};
    	int A[]={91277418,66271374,38763793,4092006,11415077,60468277,1122637,72398035,-62267800,22082642,60359529,-16540633,92671879,-64462734,-55855043,-40899846,88007957,-57387813,-49552230,-96789394,18318594,-3246760,-44346548,-21370279,42493875,25185969,83216261,-70078020,-53687927,-76072023,-65863359,-61708176,-29175835,85675811,-80575807,-92211746,44755622,-23368379,23619674,-749263,-40707953,-68966953,72694581,-52328726,-78618474,40958224,-2921736,-55902268,-74278762,63342010,29076029,58781716,56045007,-67966567,-79405127,-45778231,-47167435,1586413,-58822903,-51277270,87348634,-86955956,-47418266,74884315,-36952674,-29067969,-98812826,-44893101,-22516153,-34522513,34091871,-79583480,47562301,6154068,87601405,-48859327,-2183204,17736781,31189878,-23814871,-35880166,39204002,93248899,-42067196,-49473145,-75235452,-61923200,64824322,-88505198,20903451,-80926102,56089387,-58094433,37743524,-71480010,-14975982,19473982,47085913,-90793462,-33520678,70775566,-76347995,-16091435,94700640,17183454,85735982,90399615,-86251609,-68167910,-95327478,90586275,-99524469,16999817,27815883,-88279865,53092631,75125438,44270568,-23129316,-846252,-59608044,90938699,80923976,3534451,6218186,41256179,-9165388,-11897463,92423776,-38991231,-6082654,92275443,74040861,77457712,-80549965,-42515693,69918944,-95198414,15677446,-52451179,-50111167,-23732840,39520751,-90474508,-27860023,65164540,26582346,-20183515,99018741,-2826130,-28461563,-24759460,-83828963,-1739800,71207113,26434787,52931083,-33111208,38314304,-29429107,-5567826,-5149750,9582750,85289753,75490866,-93202942,-85974081,7365682,-42953023,21825824,68329208,-87994788,3460985,18744871,-49724457,-12982362,-47800372,39958829,-95981751,-71017359,-18397211,27941418,-34699076,74174334,96928957,44328607,49293516,-39034828,5945763,-47046163,10986423,63478877,30677010,-21202664,-86235407,3164123,8956697,-9003909,-18929014,-73824245};
    	vector<int> B(A,A+27);
    	vector<vector<int> > res=fourSum(B,-236727523);
    	for(int i=0;i<res.size();i++){
    		for(int j=0;j<4;j++)
    			cout<<res[i][j]<<" ";
    		cout<<endl;
		}

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
