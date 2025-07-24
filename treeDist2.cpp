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

vector<int> tree[maxN];
int height[maxN];
int parent[maxN];

void dfs2(int v, int par = -1){
	parent[v] = par;
	for(auto child: tree[v]){
		if(child != par){
			height[child] = 1+height[v];
			dfs2(child,v);
		}
	}
}

vector<int> path(int x){
	vector<int> path_x;
	while(x != -1){
		path_x.push_back(x);
		x = parent[x];
	}
	return path_x;
}

int main(){
	int n;
	cin >> n;
	for(int i = 0; i < n-1; i++){
		int x, y;
		cin >> x >> y;
		tree[x].push_back(y);
		tree[y].push_back(x);
	}
	dfs2(1);
	// parent[1] = 1;
	map<int,vector<int>> m;
	for(int i = 1; i <= n; i++){
		vector<int> path_i = path(i);
		reverse(path_i.begin(),path_i.end());
		m[i] = path_i;
	}
}