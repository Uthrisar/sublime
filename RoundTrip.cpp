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

#define endl '\n'
#define ff first
#define ss second
#define ll long long 
#define pb push_back
#define pi pair<int,int>
#define vi vector<int>
#define mi map<int,int>
#define vv vector<vector<int>>
#define all(v) (v).begin(),(v).end()
#define sumAll(v) accumulate(all(v),0)
#define maxHeap priority_queue<int>
#define minHeap priority_queue<int,vector<int>,greater<int>>

using namespace std;

const int mxN = 2e5+5;
const int MOD = 1e9+7;
const int INF = 1e9+5;



// vi graph[mxN];
// bool vis[mxN];
// int par[mxN];

bool cmp(pi a, pi b){
	// if(a.ff != b.ff){
	// 	return b.ff > a.ff;
	// }
	// return a.ss > b.ss;

	int x = a.ff + a.ss;
	int y = b.ff + b.ss;
	return x < y;
}

void solve(){
	int xc, yc, k;
	cin >> xc >> yc >> k;
	vector<pi> ans(k);
	ll tot_x = xc*1LL*k;
	ll tot_y = yc*1LL*k;
	for(int i = 1; i <= k; i++){
		ans[i-1].ff = i;
		ans[i-1].ss = 2*xc-i;
	}
	for(int i = 0; i < k; i++){
		cout << ans[i].ff <<" "<<ans[i].ss<<endl;
	}
}

int main(){
	int t;
	cin >> t;
	for(int i = 1; i <= t; i++){
		// cout << "Case #" << i << ": ";
		solve();
	}
}