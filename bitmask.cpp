#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;
	cin >> n;
	vector<int> masks(n,0);
	for(int i = 0; i < n; i++){
		int numWorkers;
		cin >> numWorkers;
		int mask = 0;
		for(int j = 0; j < numWorkers; j++){
			int day;
			cin >> day;
			mask = (mask|(1<<day));
		}
		masks[i] = mask;
	}
	int mx_days = 0;
	for(int i = 0; i < n; i++){
		for(int j = i+1; j < n; j++){
			int joint = (masks[i] & masks[j]);
			int commmonDays = __builtin_popcount(joint);
			mx_days = max(mx_days,commmonDays);
		}
	}
	cout << mx_days <<"\n";
}