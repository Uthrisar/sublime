#include<bits/stdc++.h>
using namespace std;

int main(){
	int n, x;
	cin >> n >> x;
	vector<int> v1(n);
	for(auto & e: v1){
		cin >> e;
	}
	vector<int> dp(1e6+1,1e9+5);
	dp[0] = 0;
	for(int i = 1; i <= x; ++i){
		for(int j = 0; j < n; ++j){
			if(i >= v1[j]){
				dp[i] = min(dp[i],dp[i-v1[j]]+1);
			}
		}
	}
	dp[x] == 1e9+5 ? cout << -1 <<"\n" : cout << dp[x] <<"\n";
}