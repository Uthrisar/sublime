#include<iostream>
#include<queue>
#include<map>
#include<set>
#include<vector>
#include<string>
#include<algorithm>
#include<cmath>
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

void solve(){
	int n, q;
	cin >> n >> q;
	vector<int> A(n), K(q);
	for(int i = 0; i < n; i++){
		cin >> A[i];
	}
	for(int i = 0; i < q; i++){
		cin >> K[i];
	}
	for(int i = 0; i < q; i++){
		vector<long long> subArr;
		for(int j = 0; j < K[i]; j++){
			subArr.push_back(A[j]);
		}
		sort(subArr.begin(),subArr.end());
		int first = 0, last = K[i]-1;
		while(last-first >= 2){
			subArr[last-1] += subArr[last]-subArr[first];
			first++;
			last--;
		}
		cout << subArr[first] <<" ";
	}
	cout << "\n";
}

int main(){
	int tc;
	cin >> tc;
	while(tc--){
		solve();
	}
}