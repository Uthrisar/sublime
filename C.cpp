#include<bits/stdc++.h>
using namespace std;
int maxA = 1e9+1;
void solve(){
	int n, k;
	cin >> n >> k;
	vector<int> durr(n+1);
	for(int i = 1; i <= n; i++){
		cin >> durr[i];
	}
    int left = 1;
    int right = n;
    int cnt = 0;
    while(k>0 && left < right){
        int min_el = min(durr[left],durr[right]);
        if(2*min_el <= k){
            k -= 2*min_el;
            durr[left] -= min_el;
            durr[right] -= min_el;
            if(durr[left] == 0){
                cnt++;
                left++;
            } 
            if(durr[right] == 0){
                cnt++;
                right--;
            } 
        } else {
            if((k&1) && (int(k/2)+1 == durr[left])){
                cnt++;
            }
            break;
        }
    }
    if(left == right){
        if(k >0 && k >= durr[left]){
            cnt++;
        }
    }
    cout << cnt <<"\n";
}

int main(){
	int tc;
	cin >> tc;
	while(tc--){
		solve();
	}
}