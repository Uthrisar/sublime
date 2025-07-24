#include<iostream>
#include<queue>
#include<stack>
#include<map>
#include<set>
#include<vector>
#include<string>
#include<cmath>
#include<cstring>
#include<algorithm>
using namespace std;

const int maxN = 2e5+5;
const int MOD = 1e9+7;
const int INF = 1e9+5;

#define ll long long 

ll val[101];
ll wt[101];
ll dp[101][100001];

ll f(int ind, ll val_left){
	if(val_left == 0) return 0;
	if(ind < 0) return 1e9+5;
	if(dp[ind][val_left] != -1) return dp[ind][val_left];
	ll ans = f(ind-1, val_left);
	if(val_left >= val[ind]){
		ans = min(ans, f(ind-1, val_left-val[ind])+wt[ind]);
	}
	return dp[ind][val_left] = ans;
}

int main(){
	memset(dp,-1,sizeof(dp));
	ll mx_val = 1e5;
	int n, w;
	cin >> n >> w;
	for(int i = 0; i < n; i++){
		cin >> wt[i] >> val[i];
	}
	for(ll i = mx_val; i >= 0; i--){
		if(f(n-1,i) <= w){
			cout << i << "\n";
			break;
		}
	}
}