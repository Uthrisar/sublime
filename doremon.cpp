#include<iostream>
#include<queue>
#include<stack>
#include<map>
#include<set>
#include<vector>
#include<string>
#include<cmath>
#include<cstring>
#include<unordered_map>
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

// vector<int> graph[maxN];
// bool vis[maxN];

bool cmp(pair<int,int> a, pair<int,int> b){
	// if(a.first != b.first){
	// 	return b.first > a.first;
	// }
	// return a.second > b.second;

	int x = a.first + a.second;
	int y = b.first + b.second;
	return x < y;
}

// void dfs(int u){
// 	for(auto v: graph[u]){
// 		if(!vis[u]){
// 			dfs(v);
// 		}
// 	}
// }

void solve(){
	int n;
	cin >> n;
	vector<int> v1(n);
	vector<int> freq(maxN,0);
	for(int i = 0; i < n; i++){
		cin >> v1[i];
		freq[v1[i]] += 1;
	}
	int m;
	cin >> m;
	vector<int> v3;
	vector<int> v4;
	for(int i = 0; i < m; i++){
		int x;
		cin >> x;
		int f = freq[x];
		if(f > 0){
			freq[x] = 0;
			while(f--){
				v3.push_back(x);
			}
		}
	}
	for(int i = 0; i < maxN; i++){
		if(freq[i] != 0){
			v4.push_back(i);
		}
	}
	sort(v4);
	for(int i = 0; i < v3.size(); i++){
		cout << v3[i] <<" ";
	}
	for(auto el: v4){
		cout << el <<" ";
	}
	cout <<"\n";
}

int main(){
	int tc;
	cin >> tc;
	while(tc--){
		solve();
	}
}