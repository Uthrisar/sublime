#include<bits/stdc++.h>
using namespace std;

const int N = 2e5+10;
bool vis[N];
vector<int> g[N];
vector<vector<int>> cc;
vector<int> curr_cc;

void dfs(int u){
	vis[u] = 1;
	curr_cc.push_back(u);
	for(auto v: g[u]){
		if(!vis[v]){
			dfs(v);
		}
	}
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
	for(int i = 1; i <= n; i++){
		if(!vis[i]){
			curr_cc.clear();
			dfs(i);
			cc.push_back(curr_cc);
		}
	}
	cout << cc.size() << "\n";
	for(auto vec: cc){
		cout << "size = " << vec.size() << " and elements : ";
		for(auto el: vec){
			cout << el <<" ";
		}
		cout << "\n";
	}
}