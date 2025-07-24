#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> deleteAndEarn(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        vector<int> dp(n, -1);
        dp[0] = nums[0];
        for(int i=1; i<n; i++){
            rec(i, nums, dp);
        }
        return dp;
    }

    int rec(int i, vector<int>& a, vector<int>& dp){
        if(i == -1) return 0;
        if(dp[i]!= -1) return dp[i];
        int ans = 0;
        for(int j=-1; j<i; j++){
            if(j == -1 || a[i] > a[j]+1 || a[i] == a[j]){
                ans = max(ans, rec(j, a, dp)+a[i]);
            }
        }
        return dp[i] = ans;
    }
};

int main(){
    int num;
    vector<int> nums;
    while(cin>>num){
        nums.push_back(num);
    }
    Solution sol;
    vector<int> ans = sol.deleteAndEarn(nums);
    for(auto e : ans){
        cout<<e<<" ";
    }
}