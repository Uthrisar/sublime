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

const long long MOD = 1e9+7;

long long dp[105][100005];


long long func(int idx, int K, vector<int>& v1){
	if(K == 0) return 1;
	if(idx < 0) return 0;
	if(dp[idx][K] != -1) return dp[idx][K];
	long long ways = 0;
	for(int num_candy = 0; num_candy <= v1[idx]; num_candy++){
		if(K >= num_candy){
			ways += func(idx-1, K-num_candy, v1)%MOD;
		}
	}
	return dp[idx][K] = ways;
}

int main(){
	memset(dp,-1,sizeof(dp));
	int n, k;
	cin >> n >> k;
	vector<int> v1(n);
	for(int i = 0; i < n; i++){
		cin >> v1[i];
	}
	cout << func(n-1,k,v1) <<"\n";
}