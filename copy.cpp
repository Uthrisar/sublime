#include <bits/stdc++.h>
using namespace std;

const int maxN = 2e5+5;
const int MOD = 1e9+7;
const int INF = 1e9+5;

#define pi pair<int,int>
#define si set<int>
#define spi set<pi>
#define msi multiset<int>
#define mspi multiset<pi>
#define mi map<int,int>
#define ll long long
#define sort(v) sort(v.begin(),v.end())
#define maxheap priority_queue<int>
#define minheap priority_queue<int,vector<int>,greater<int>>

bool cmp(pair<int,int> a, pair<int,int> b){
	// if(a.first != b.first){
	// 	return b.first > a.first;
	// }
	// return a.second > b.second;

	int x = a.first + a.second;
	int y = b.first + b.second;
	return x < y;
}

void solve(){
	string s1;
	cin >> s1;
	int n = s1.size();
	int bal = 0;
	int validPairs = 0;

	vector<int> balCnt(2*n+1,0);
	balCnt[n] = 1;

	for(char ch: s1){
		if(ch == '('){
			bal++;
		} else {
			bal--;
		}
		validPairs += balCnt[bal+n];
		balCnt[bal+n]++;
	}
	cout << validPairs <<"\n";
}

int main(){
	int tc;
	cin >> tc;
	while(tc--){
		solve();
	}
}