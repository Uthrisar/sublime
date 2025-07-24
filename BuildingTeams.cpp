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

const int mxN = 1e5+5;
const int MOD = 1e9+7;
const int INF = 1e9+5;



vector<int> graph[mxN];
bool vis[mxN];
int col[mxN];

bool dfs(int v){
	vis[v] = 1;
	for(int child: graph[v]){
		if(vis[child] && col[v] == col[child]) return false;
		if(vis[child]) continue;
		col[child] = !col[v];
		if(!dfs(child)) return false;
	}
	return true;
}

int main(){
	int n, m;
	cin >> n >> m;
	for(int i = 1; i <= m; ++i){
		int a, b;
		cin >> a >> b;
		graph[a].pb(b);
		graph[b].pb(a);
	}
	bool ans = true;
	for(int i = 1; i <= n; i++){
		if(!vis[i]){
			if(!dfs(i)) {
				ans = false;
				break;
			}
		}
	}
	if(ans) {
		for(int i = 1; i <= n; i++){
			cout << col[i]+1 << " ";
		}
	} else {
		cout << "IMPOSSIBLE" << endl;
	}
}