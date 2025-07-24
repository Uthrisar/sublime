#include<bits/stdc++.h>
#define nline endl
#define ll long long
#define si set<int>
#define vi vector<int>
#define pi pair<int,int>
#define mi map<int,int>
#define ALL(v) v.begin(),v.end()

using namespace std;

const int mxN = 1e5+5;
const int MOD = 1e9+7;
const int INF = 1e9+10;

pair<ll,int> digitSum(ll n){
	ll sum = 0;
	int mx = -1;
	while(n > 0){
		sum += (n%10);
		mx = max(mx, int(n%10));
		n /= 10;
	}
	return {sum,mx};
}

void nextGreater(){
	stack<int> s;
	int n;
	cin >> n;
	vi v(n);
	vi nextG(n,-1);
	for(int i = 0; i < n; i++){
		cin >> v[i];
		while(s.size() > 0 && v[s.top()] < v[i]){
			nextG[s.top()] = i;
			s.pop();
		}
		s.push(i);
	}
	for(int i = 0; i < n; i++){
		nextG[i] != -1 ? cout << v[nextG[i]] <<" ": cout << -1 <<" ";
	}
}

class Mex {
private:
    mi frequency;
    si missing_numbers;
    vi A;

public:
    Mex(vector<int> const& A) : A(A){
        for(int i = 0; i <= A.size(); i++)
            missing_numbers.insert(i);
        for(int x : A) {
            frequency[x]++;
            missing_numbers.erase(x);
        }
    }
    
    int mex(){
        return *missing_numbers.begin();
    }

    void update(int idx, int new_value) {
        if(--frequency[A[idx]] == 0){
            missing_numbers.insert(A[idx]);
        }
        A[idx] = new_value;
        frequency[new_value]++;
        missing_numbers.erase(new_value);
    }
};


vector<bool> is_prime(mxN, true);
vector<int> lp(mxN, 0), hp(mxN, 0);

void seive(){
	is_prime[0] = is_prime[1] = false;
	for(int i = 2; i < mxN; i++){
		if(is_prime[i]){
			hp[i] = lp[i] = i;
			for(int j = 2*i; j < mxN; j += i){
				is_prime[j] = false;
				hp[j] = i;
				if(lp[j] == 0){
					lp[j] = i;
				}
			}
		}
	}
}

void prime_fact(int n){
	unordered_map<int,int> primeCount;
	int pr_fact;
	while(n > 1){
		pr_fact = hp[n];
		while(n % pr_fact == 0){
			primeCount[pr_fact]++;
			n /= pr_fact;
		}
	}
	for(auto pr : primeCount){
		cout << pr.first << " " << pr.second << nline;
	}
}

void solve(){

}

int main() {
    // int test_case;
    // cin >> test_case;
    // while(test_case--)
    // 	solve();
    
    // int n;
    // cin >> n;
    // vi v1(n);
    // for(int i = 0; i < n; i++)
    // 	cin >> v1[i];
    // Mex M(v1);
    // cout << M.mex() << nline;

    // int a1 = 225*7*12;
    // cin >> a1;
    // seive();
    // prime_fact(a1);
}
