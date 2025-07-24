#include<bits/stdc++.h>
using namespace std;

const int N = 2e5+10;
bool vis[N];
vector<int> g[N];

bool dfs(int u, int p){
	vis[u] = 1;
	for(auto v: g[u]){
		if(!vis[v]){
			if(dfs(v,u)) return true;
		} else {
			if(v != p) return true;
		}
	}
	return false;
}
int main(){
	int n, m;
	cin >> n >> m;
	for(int i = 0; i < m; i++){
		int x, y;
		cin >> x >> y;
		g[x].push_back(y);
		g[y].push_back(x);
	}
	bool isLoop = false;
	for(int i = 1; i <= n; i++){
		if(!vis[i]){
			isLoop = isLoop || dfs(i,-1);
		}
	}
	isLoop ? cout <<"Yes\n" : cout <<"No\n";
}