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

vector<int> a(maxN);
vector<int> g[maxN];
int m;
int ans = 0;
void dfs(int u, int p, int mx, int mxC){
	if(a[u] == 0){
		mxC = max(mx, mxC);
		mx = 0;
	} else {
		mx++;
	}
	int numChild = 0;
	for(auto v: g[u]){
		if(v != p){
			dfs(v, u, mx, mxC);
			numChild++;
		}
	}
	if(numChild == 0){
		mxC = max(mx, mxC);
		if(mxC <= m){
			ans++;
		}
	}
}

// void solve(){
	
// }

int main(){
	// int tc;
	// cin >> tc;
	// while(tc--){
	// 	solve();
	// }
	int n;
	cin >> n >> m;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
	}
	for(int i = 0; i < n-1; i++){
		int y, z;
		cin >> y >> z;
		g[y].push_back(z);
		g[z].push_back(y);
	}
	dfs(1,-1,0,0);
	cout << ans <<"\n";
}