#include<iostream>
#include<queue>
#include<map>
#include<set>
#include<vector>
#include<string>
#include<cmath>
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

vector<int> graph[maxN];
bool vis[maxN];

bool cmp(pair<int,int> a, pair<int,int> b){
	// if(a.first != b.first){
	// 	return b.first > a.first;
	// }
	// return a.second > b.second;

	int x = a.first + a.second;
	int y = b.first + b.second;
	return x < y;
}

void dfs(int u){
	for(auto v: graph[u]){
		if(!vis[u]){
			dfs(v);
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
	long long H;
	cin >> H;
	H += 1;
	int cnt = 0;
	while(H >= 2){
		cnt++;
		H /= 2;
	}
	cnt += 1;
	cout << cnt <<"\n";
}