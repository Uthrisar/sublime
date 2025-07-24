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

	// int x = a.first + a.second;
	// int y = b.first + b.second;
	// return x < y;
	return a.first > a.second && b.first < b.second;
}

void dfs(int u){
	for(auto v: graph[u]){
		if(!vis[u]){
			dfs(v);
		}
	}
}

int main(){
	int N;
	cin >> N;
	map<pair<int,int>, int> m1;
	for(int i = 1; i <= N; i++){
		int A, C;
		cin >> A >> C;
		m1.insert({{A,C},i});
	}
	vector<pair<int,int>> v1;
	
}