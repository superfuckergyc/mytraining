#include<iostream>
#include<cstring>
#include<vector>
using namespace std;
int lengthOfLIS(vector<int>& nums) {
    //10 9 2 5 3 7 101 18  n=8
    int n=nums.size();
    vector<int> dp(n,1);
    for(int i=1;i<n;i++){
        for(int j=0;j<i;j++){
            if(nums[j]<nums[i]){
                dp[i]=max(dp[j]+1,dp[i]);
            }
        }
    }
    int res=0;
    for(int i=0;i<n;i++){
        res=max(res,dp[i]);
    }
    return res; 
}
int main(){
	vector<int> t;
	int num;
	while(cin>>num){
		t.push_back(num);
		if(cin.peek()=='\n'){
			break;
		}
	}
	int res=lengthOfLIS(t);
	cout<<res<<endl;
	return 0;
}