#include<cstring>
#include<climits>
#include<iostream>
#include<queue>
#include<map>
#include<set>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

const int maxN = 2e5+5;
const int MOD = 1e9+7;
const int INF = 1e9+5;

#define vi vector<int>
#define vp vector<pair<int,int>>
#define pi pair<int,int>
#define si set<int>
#define spi set<pi>
#define msi multiset<int>
#define mspi multiset<pi>
#define mi map<int,int>

bool cmp(pair<int,int> a, pair<int,int> b){
	// if(a.first != b.first){
	// 	return b.first > a.first;
	// }
	// return a.second > b.second;

	int x = a.first + a.second;
	int y = b.first + b.second;
	return x < y;
}

int mex_op(vector<int> v){
	sort(v.begin(),v.end());
	int mex = 0;
	for(auto el : v){
		if(mex == el){
			mex++;
		} else {
			break;
		}
	}
	return mex;
}
int dp[maxN];

int frog_jump(int i, int K, vector<int>& h){
	if(i == 0) return 0;
	if(dp[i] != -1) return dp[i];
	int ans = INT_MAX;
	for(int j = 1; j <= K; j++){
		if(i >= j){
			ans = min(ans,frog_jump(i-j,K,h)+abs(h[i]-h[i-j]));
		}
	}
	return dp[i] = ans;
}

int main(){
	memset(dp,-1,sizeof(dp));
	int n, K;
	cin >> n >> K;
	vector<int> heig(n);
	for(int i = 0; i < n; i++){
		cin >> heig[i];
	}
	cout << frog_jump(n-1,K,heig) << "\n";
}