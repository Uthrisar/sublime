#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin >> n;
    vector<int> x(n);
    for(int i = 0; i < n; i++){
        cin >> x[i];
    }
    for(int i = n-1; i>=0; i--){
        for(int j = 0; j < n; j++){
            dp[i][j] = max(x[i]+sum[j]-sum[i]-dp[i+1][j],x[i]+sum[j]-sum[i]+dp[i][j-1])
        }
    }
}