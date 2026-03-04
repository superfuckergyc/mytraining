#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
using namespace std;
/*给你一个整数数组 nums 和一个整数 k ，请你返回其中出现频率前 k 高的元素。你可以按 任意顺序 返回答案。
示例 1：
输入：nums = [1,1,1,2,2,3], k = 2
输出：[1,2]
示例 2：
输入：nums = [1], k = 1
输出：[1]
示例 3：
输入：nums = [1,2,1,2,1,2,3,1,3,2], k = 2
输出：[1,2] */
vector<int> func(vector<int>& nums,int k){
	unordered_map<int,int> map;
	int max_cnt=0;
	for(auto& num:nums){
		map[num]++;
		max_cnt=max(max_cnt,map[num]);
	}
	//map[1]=3    map[2]=2    map[3]=1
	vector<vector<int>> budget(max_cnt+1);
	for(auto& [x,c]:map){
	    budget[c].push_back(x);		
	}
	vector<int> res;
	for(int i=max_cnt;i>=0&&res.size()<k;i--){
		res.insert(res.end(),budget[i].begin(),budget[i].end());
	}
	return res;
}
int main(){
	vector<int> nums;
	int num,k;
	while(cin>>num){
		nums.push_back(num);
		if(cin.peek()=='\n'){
			break;
		}
	}
	cin>>k;
	vector<int> res=func(nums,k);
	int s=res.size();
	for(int i=0;i<s;i++){
		cout<<res[i];
	}
	return 0;
}
