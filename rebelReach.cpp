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

const int maxN = 2e5+5;
const int MOD = 1e9+7;
const int INF = 1e9+5;

#define pi pair<int,int>
#define si set<int>
#define spi set<pi>
#define msi multiset<int>
#define mspi multiset<pi>
#define mi map<int,int>
#define ll long long 
#define sort(v) sort(v.begin(),v.end())
#define maxheap priority_queue<int>
#define minheap priority_queue<int,vector<int>,greater<int>>


void dfs(int u, int p = -1){
	for(auto v: graph[u]){
		if(v == p) continue;
		dfs(v,u);
	}
}

void solve(){
	int n;
	cin >> n;
	for(int i = 1; i < = n-1; i++){
		int u, v;
		cin >> u >> v;
		graph[u].push_back(v);
		graph[v].push_back(u);
	}
	vector<long long> gaurd(n+1);
	for(int i = 1; i <= n; i++){
		cin >> gaurd[i];
	}
}

int main(){
	int tc;
	cin >> tc;
	while(tc--){
		solve();
	}
}