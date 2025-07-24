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

#define vi vector<int>
#define vp vector<pair<int,int>>
#define pi pair<int,int>
#define si set<int>
#define spi set<pi>
#define msi multiset<int>
#define mspi multiset<pi>
#define mi map<int,int>

bool cmp(pair<int,int> a, pair<int,int> b){
	// if(a.first != b.first){
	// 	return b.first > a.first;
	// }
	// return a.second > b.second;

	int x = a.first + a.second;
	int y = b.first + b.second;
	return x < y;
}

int mex_op(vector<int> v){
	sort(v.begin(),v.end());
	int mex = 0;
	for(auto el : v){
		if(mex == el){
			mex++;
		} else {
			break;
		}
	}
	return mex;
}
int mx_gcd;
void max_gcd(int i, int j, int n, int m, int g, vector<vi> v){
	if(i == n && j == m){
		g = __gcd(g,v[i][j]);
		mx_gcd = max(mx_gcd,g);
	}
	int s = g;
	g = __gcd(g,v[i][j]);
	if(i < n){
		g = __gcd(g,v[i][j]);
		max_gcd(i+1,j,n,m,g,v);
		g = s;
	}
	if(j < m){
		g = __gcd(g,v[i][j]);
		max_gcd(i,j+1,n,m,g,v);
		g = s;
	}
}

int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vi> v(n,vi(m));
		mx_gcd = 0;
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> v[i][j];
			}
		}
		max_gcd(0,0,n-1,m-1,0,v);
		cout << mx_gcd << "\n";
	}
}