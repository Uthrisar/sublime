#include<bits/stdc++.h>
using namespace std;
const int N = 2e5+1;
vector<int> tree[N];
int boss[N][N];
bool vis[N];
void bfs(int source){
	queue<int> q;
	q.push(source);
	while(!q.empty()){
		int v = q.front();
		vis[v] = true;
		q.pop();
		for(auto child: tree[v]){
			if(vis[child]) continue;
			depth[child] = 1+depth[v];
			boss[child][depth[child]] = v;
			q.push(child);
		}
	}
}
int main(){
	int n, q;
	cin >> n >> q;
	for(int i = 2; i <= n; i++){
		int x;
		cin >> x;
		tree[i].push_back(x);
		tree[x].push_back(i);
	}
	bfs(1);
	while(q--){
		int node, bossLevel;
		cin >> node >> bossLevel;

	}
}