#include <bits/stdc++.h>
using namespace std;

bool cmp(pair<int,int>& p, pair<int,int>& q){
	return (p.second-p.first) < (q.second-q.first);
}

int main(){
	int n;
	cin >> n;
	vector<pair<int, int>> arr(n);
	for(int i=0; i<n; i++){
		cin >> arr[i].first >> arr[i].second;
	}
	sort(arr.begin(), arr.end(), cmp);
	for(auto& pr : arr){
		cout << pr.first <<" "<<pr.second<<endl;
	}
}