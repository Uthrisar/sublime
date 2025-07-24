#include<bits/stdc++.h>
using namespace std;
#define nline "\n"
int main(){
	int n, x;
	cin >> n >> x;
	vector<int> prices(n), pages(n);
	for(int i = 0; i < n; ++i){
		cin >> prices[i];
	}
	for(int i = 0; i < n; ++i){
		cin >> pages[i];
	}
	vector<vector<int>> dp(n+1,vector<int>(x+1,0));
	for(int i = n-1; i >= 0; i--){
		for(int j = 0; j <= x; j++){
			dp[i][j] = max(dp[i][j],dp[i+1][j]);
			if(j>=prices[i]){
				dp[i][j] = max(dp[i][j],dp[i+1][j-prices[i]]+pages[i]);
			}
		}
	}
	cout << dp[0][x] << nline;
}