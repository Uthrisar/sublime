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
#define ll long long 
#define sort(v) sort(v.begin(),v.end())
#define maxheap priority_queue<int>
#define minheap priority_queue<int,vector<int>,greater<int>>


int recc(int a, int b){
	if(b == 0) return 1;
	int res = recc(a, b/2);
	if(b&1){
		return (a*(res*1LL*res)%MOD)%MOD;
	} else {
		return (res*1LL*res)%MOD;
	}
}

int solve(){
	
}

int main(){
	// int tc;
	// cin >> tc;
	// while(tc--){
	// 	solve();
	// }
	int a = 100, b = 10000;
	cout << recc(a,b) <<"\n";
}