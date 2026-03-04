#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;
/*
给你一个按照非递减顺序排列的整数数组 nums，和一个目标值 target。请你找出给定目标值在数组中的开始位置和结束位置。
如果数组中不存在目标值 target，返回 [-1, -1]。
你必须设计并实现时间复杂度为 O(log n) 的算法解决此问题。
示例 1：
输入：nums = [5,7,7,8,8,10], target = 8
输出：[3,4]
示例 2：
输入：nums = [5,7,7,8,8,10], target = 6
输出：[-1,-1]
示例 3：
输入：nums = [], target = 0
输出：[-1,-1]
*/
vector<int> Find(vector<int>& nums,int target){
	vector<int> res;
        if(nums.size()==0)return {-1,-1};
	    int l=0,r=nums.size()-1;//0 8
	    int mid=(l+r)/2;//4
	    while(nums[mid]!=target&&l<=r){
		    if(nums[mid]<target){
			    l=mid+1;
			    mid=(l+r)/2;
		    }
		    else if(nums[mid]>target){
			    r=mid-1;
			    mid=(l+r)/2;
		    }
	    }
	    if(nums[mid]!=target)return {-1,-1};
	    int lg=mid,rg=mid;
	    while(lg-1>=0&&nums[lg-1]==target)lg--;
        while(rg+1<nums.size()&&nums[rg+1]==target)rg++;
        res.push_back(lg);
        res.push_back(rg);
	    return res;
}
int main(){
	vector<int> nums;
	int target,num;
	while(cin>>num){
		if(cin.peek()=='\n')break;
		nums.push_back(num);
	}
	cin>>target;
	vector<int> res=Find(nums,target);
	for(int i=0;i<2;i++){
		cout<<res[i]<<" ";
	}
	return 0;
}

