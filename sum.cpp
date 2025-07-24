#include<bits/stdc++.h>
using namespace std;
void solve(){
	int n; cin >> n;
	string str; cin >> str;
	vector<int> v;
	if(n == 2 && str == "00"){
		cout <<"YES"<<"\n";
		return;
	}
	if(n == 2){
		cout <<"NO"<<"\n";
		return;
	}
	if(n == 1 && str == "0"){
		cout << "YES"<<"\n";
		return;
	} 
	if(n == 1){
		cout << "NO"<<"\n";
		return;
	}
	int cnt = 0;
	for(int i = 0; i < n; i++){
		if(str[i] == '1'){
			cnt++;
			v.push_back(i);
		}
	}
	if(cnt == 2 && ((v[1]-v[0]) == 1)){
		cout << "NO"<<"\n";
		return;
	} 
	if(cnt&1){
		cout << "NO"<<"\n";
	} else {
		cout <<"YES"<<"\n";
	}
}
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		solve();
	}
}