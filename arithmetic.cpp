#include<bits/stdc++.h>
using namespace std;
int maxA = 1e9+1;
void solve(){
	int n, c, d;
	cin >> n >> c >> d;
	int freq[maxA] = {0};
	int min_el = 1e9+10;
	for(int i = 0; i < n*n; i++){
		int x;
		cin >> x;
		min_el = min(min_el,x);
		freq[x]++;
		if(freq[x] > 1){
			cout << "NO"<<"\n";
		}
		return;
	}
	int arr[n][n];
	arr[0][0] = min_el;
	bool ans = true;
	for(int i = 0; i < n-1; i++){
		for(int j = 0; j < n-1; j++){
			arr[i][j+1] = arr[i][j]+d;
			if(!freq[arr[i][j+1]]){
				ans = false;
				break;
			}
		}
		arr[i+1][0] = arr[i][0]+c;
		if(!ans || !freq[arr[i+1][0]]){
			ans = false;
			break;
		}
	}
	if(ans){
		cout <<"YES"<<"\n";
	} else {
		cout <<"NO"<<"\n";
	}
}

int main(){
	int tc;
	cin >> tc;
	while(tc--){
		solve();
	}
}