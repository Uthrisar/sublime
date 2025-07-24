#include<iostream>
#include<queue>
#include<map>
#include<set>
#include<vector>
#include<unordered_set>
#include<unordered_map>
#include<string>
using namespace std;

const int maxN = 2e5+5;
const int MOD = 1e9+7;
const int INF = 1e9+5;

class Solution {
public:
	vector<int> dp;
	int longIncSub(int idx, vector<int>& v){
		if(dp[idx] != -1) return dp[idx];
        int ans = 1;
        for(int i = 0; i < idx; i++){
            if(v[i] < v[idx]){
                ans = max(ans, longIncSub(i, v) + 1);
            }
        }
        return dp[idx] = ans;
    }

    int lengthOfLIS(vector<int>& nums) {
    	dp.assign(nums.size(),-1);
        int answer = 0;
        for(int i = 0; i < nums.size(); i++){
            answer = max(answer, longIncSub(i, nums));
        }
        return answer;
    }
};


int main(){
    int n;
    cin >> n;
    vector<int> vect(n);
    for(int i = 0; i < n; i++){
        cin >> vect[i];
    }
    Solution sol;
    cout << sol.lengthOfLIS(vect);
}
