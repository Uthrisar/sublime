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

bool vis[maxN];
int col[maxN];
vector<int> g[maxN];

bool dfs(int u){
	vis[u] = 1;
	for(auto v: g[u]){
		if(col[u] == col[v]) return false;
		if(!vis[v]){
			col[v] = !col[u];
			if(dfs(v) == false) return false;
		}
	}
	return true;
}

int main(){
	int n, m;
	cin >> n >> m;
	col[1] = 1;
	for(int i = 0; i < m; i++){
		int x, y;
		cin >> x >> y;
		g[x].push_back(y);
		g[y].push_back(x);
	}
	dfs(1) ? cout << "Yes\n": cout <<"No\n";
}