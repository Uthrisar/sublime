#include <bits/stdc++.h>
using namespace std;

class seive {
    static const int MAXN = 100005;
    vector<int> divs[MAXN];
    int sum_divs[MAXN];

public:
    seive(){
        divs[0].push_back(0);
        sum_divs[0] = 0;
        for(int i = 1; i < MAXN; i += 1) {
            for(int j = i; j < MAXN; j += i) {
                divs[j].push_back(i);
                sum_divs[j] += i;
            }
        }
    }

    vector<int> divisors(int n) {
    	return divs[n];
    }

    int sum_divisors(int n) {
       	return sum_divs[n];
    }

};

void solve(){
	// int64_t n;
	// cin >> n;
	// int64_t n1 = n/3, n2 = n/5, n3 = n/15;
	// if(n%3 == 0) n1--;
	// if(n%5 == 0) n2--;
	// if(n%15 == 0) n3--;
	// int64_t sum = 0;
	// sum += (n1*(6+(n1-1)*3))/2;
	// sum += (n2*(10+(n2-1)*5))/2;
	// sum -= (n3*(30+(n3-1)*15))/2;
	// cout << sum <<"\n";


	int64_t n;
    cin >> n;
    int64_t first = 1, second = 2;
    int64_t nxt_t = 2;
    int64_t ans = 0;
    while(nxt_t < n){
        ans += nxt_t;
        for(int i = 0; i < 3; ++i){
            nxt_t = first+second;
            first = second;
            second = nxt_t;
        }
    }
    cout << ans <<"\n";
}

int main() {
    // int n;
    // cin >> n;
    // seive s;
    // cout << s.sum_divisors(n) <<"\n";
    // vector<int> v2 = s.divisors(n);
    // for(auto e : v2){
    // 	cout << e <<" ";
    // }
    // return 0;

    int tc;
    cin >> tc;
    while(tc--){
    	solve();
    }
}
