#include<bits/stdc++.h>
using namespace std;

const int MOD = 1e9+7;

int main(){
	int n, x;
	cin >> n >> x;
	vector<int> coins(n);
	for(auto & coin: coins){
		cin >> coin;
	}
	vector<vector<int>> dp(n+1,vector<int>(x+1));
	for(int i = 0; i <= n; ++i){
		dp[i][0] = 1;
	}
	int pick;
	for(int i = n-1; i >= 0; i--){
		for(int j = 0; j <= x; j++){
			pick = 0;
			if(j>=coins[i]){
				pick = dp[i][j-coins[i]];
			}
			dp[i][j] = (pick+dp[i+1][j])%MOD;
		}
	}
	cout << dp[0][x] <<"\n";
}