#include<iostream>
#include<queue>
#include<map>
#include<set>
#include<vector>
#include<string>
#include<algorithm>
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

bool cmp(pair<int,int> a, pair<int,int> b){
	// if(a.first != b.first){
	// 	return b.first > a.first;
	// }
	// return a.second > b.second;

	int x = a.first + a.second;
	int y = b.first + b.second;
	return x < y;
}

int mex_op(vector<int> v){
	sort(v.begin(),v.end());
	int mex = 0;
	for(auto el : v){
		if(mex == el){
			mex++;
		} else {
			break;
		}
	}
	return mex;
}

void rec(int idx,int k,vector<int> curr_v){
	if(k == 0) {
		
	}
	rec(idx+1,k,curr_v);
	curr_v.push_back(idx);
	rec(idx+1,k-idx,curr_v);
	curr_v.pop_back();
}

void solve(){
	int a, b, c, d;
	cin >> a >> b >> c >> d;
	int ct = 0;
	for(int i = min(a,b)+1; i < max(a,b); i++){
		if(c == i) ct++;
		if(d == i) ct++;
	}
	ct == 1 ? cout << "Yes\n": cout << "No\n";
	
}

int main(){
	int tc;
	cin >> tc;
	while(tc--){
		solve();
	}
}