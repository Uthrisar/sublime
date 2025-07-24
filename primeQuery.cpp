#include <bits/stdc++.h>
using namespace std;

void solve(){
	int N;
	cin >> N;
	vector<int> V(N+1);
	for(int i = 1; i <= N; i++){
		cin >> V[i];
	}
	vector<int> cnt_one(N+10,0),cnt_zero(N+10,0);
	for(int i = 1; i <= N; i++){
		if(V[i] == 0){
			cnt_zero[i] = cnt_zero[i-1]+1;
		} else {
			cnt_zero[i] = cnt_zero[i-1];
		}
		if(V[i] == 1){
			cnt_one[i] = cnt_one[i-1]+1;
		} else {
			cnt_one[i] = cnt_one[i-1];
		}
	}

	int Q;
	cin >> Q;
	while(Q--){
		int L, R;
		cin >> L >> R;
		long long tot_n = R-L+1;
		long long cnt_1 = cnt_one[R]-cnt_one[L-1];
		long long cnt_0 = cnt_zero[R]-cnt_zero[L-1];
		long long ans;
		if(cnt_0 > 0){
			ans = ((tot_n*(tot_n-1))/2-(cnt_0*(cnt_0-1))/2) - (cnt_1*cnt_0);
		} else {
			ans = (tot_n*(tot_n-1))/2;
		}
		cout << ans << "\n";
	}
}

int main() {
	int tc;
	cin >> tc;
	while(tc--){
		solve();
	}
}