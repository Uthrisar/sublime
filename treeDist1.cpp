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

vector<int> tree[maxN];
int in[maxN];
int out[maxN];

void dfs3(int v, int par = -1){
	int mx1 = -1, mx2 = -1;
	for(auto neigh: tree[v]){
		if(neigh != par){
			if(mx1 < in[neigh]){
				mx2 = mx1;
				mx1 = in[neigh];
			}
			else if(mx2 < in[neigh]){
				mx2 = in[neigh];
			}
		}
	}
	for(auto child: tree[v]){
		if(child != par){
			int longest = mx1;
			if(mx1 == in[child]){
				longest = mx2;
			}
			out[child] = 1+max(out[v],1+longest);
			dfs3(child,v);
		}
	}
}

void dfs2(int v, int par = -1){
	for(auto child: tree[v]){
		if(child != par){
			dfs2(child,v);
			in[v] = max(in[v],1+in[child]);
		}
	}
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
	dfs3(1);
	for(int i = 1; i <= n; i++){
		cout << max(in[i],out[i]) <<" ";
	}
}