#include<bits/stdc++.h>
using namespace std;
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<int> v1(n);
		for(int i = 0; i < n; i++){
			cin >> v1[i];
		}
		vector<int> v2(n-1);
		for(int i = 0; i < n-1; i++){
			v2[i] = __gcd(v1[i],v1[i+1]);
		}
		for(int i = 0; i < n-1; i++){
			cout << v2[i] <<" ";
		}
		cout << "\n";
		int cnt = 0;
		for(int i = 0; i < n-2; i++){
			if(v2[i] > v2[i+1]){
				cnt++;
			}
		}
		cout << cnt << " ";
		if(cnt == 0 ){
			cout << "Yes\n";
		} else if(cnt == 1){
			int ind;
			vector<int> v3;
			for(int i = 0; i < n-2; i++){
				if(v2[i] > v2[i+1]){
					ind = i;
					break;
				}
			}

		} else {
			cout << "No\n";
		}
	}
}