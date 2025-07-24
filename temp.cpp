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

#define endl '\n'
#define ff first
#define ss second
#define ll long long 
#define pb push_back
#define pi pair<int,int>
#define vi vector<int>
#define mi map<int,int>
#define vv vector<vector<int>>
#define all(v) (v).begin(),(v).end()
#define sumAll(v) accumulate(all(v),0)
#define maxHeap priority_queue<int>
#define minHeap priority_queue<int,vector<int>,greater<int>>

using namespace std;

const int mxN = 2e5+5;
const int MOD = 1e9+7;
const int INF = 1e9+5;

map<int,int> movements = {
	{-1,0},{1,0},{0,1},{0,-1}
};

bool cmp(pi a, pi b){
	// if(a.ff != b.ff){
	// 	return b.ff > a.ff;
	// }
	// return a.ss > b.ss;

	int x = a.ff + a.ss;
	int y = b.ff + b.ss;
	return x < y;
}

// vi isPrime(mxN,1);
// vi hp(mxN,0), lp(mxN,0);
// void seive(){
// 	isPrime[0] = isPrime[1] = false;
// 	for(int i = 2; i < mxN; i++){
// 		if(isPrime[i] == true){
// 			hp[i] = lp[i] = i;
// 			for(int j = 2*i; j < mxN; j += i){
// 				isPrime[j] = false;
// 				hp[j] = i;
// 				if(lp[j] == 0){
// 					lp[j] = i;
// 				}
// 			}
// 		}
// 	}
// }
// vi primeFactors(int n){
// 	vi prime_factors;
// 	int pr_fact;
// 	while(n > 1){
// 		pr_fact = lp[n];
// 		while(n % pr_fact == 0){
// 			prime_factors.push_back(pr_fact);
// 			n /= pr_fact;
// 		}
// 	}
// 	return prime_factors;
// }

// bool isAlphabet(char ch){
// 	return int(ch) >= 97 && int(ch) <= 122;
// }


void solve(){
	
}

int main(){
	int t;
	cin >> t;
	for(int i = 1; i <= t; i++){
		// cout << "Case #" << i << ": ";
		solve();
	}
}