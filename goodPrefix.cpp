#include<iostream>
#include<queue>
#include<stack>
#include<map>
#include<set>
#include<vector>
#include<string>
#include<cmath>
#include<cstring>
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
#define ll long long 
#define sort(v) sort(v.begin(),v.end())
#define maxheap priority_queue<int>
#define minheap priority_queue<int,vector<int>,greater<int>>


void solve(){
	int n;
	cin >> n;
	vector<long long> v(n);
	for(int i = 0; i < n; i++){
		cin >> v[i];
	}
	long long mx = -1;
	long long sum = 0;
	int count = 0;
	for(int i = 0; i < n; i++){
		mx = max(v[i], mx);
		sum += v[i];
		if(2*mx == sum){
			count++;
		}
	}
	cout << count <<"\n";
}

int main(){
	int tc;
	cin >> tc;
	while(tc--){
		solve();
	}
}