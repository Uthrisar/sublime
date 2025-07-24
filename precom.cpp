#include<bits/stdc++.h>
using namespace std;

void solve(){
	int n, q;
	cin >> n >> q;
	vector<int> v1(n+5);
	while(q--){
		int a, b, k;
		cin >> a >> b >> k;
		v1[a] += k;
		v1[b+1] -= k;
	}
	for(int i = 1; i <= n; i++){
		v1[i] += v1[i-1];
	}
	for(int i = 1; i <= n; i++){
		cout << v1[i] << " ";
	}
}

int main(){
	int tc;
	cin >> tc;
	while(tc--){
		solve();
	}
}