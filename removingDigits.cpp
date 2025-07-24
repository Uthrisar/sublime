#include<bits/stdc++.h>
using namespace std;
#define nline "\n"
int main(){
	int n;
	cin >> n;
	vector<int> dp(n+1,1e9+10);
	int j;
	dp[0] = 0;
	for(int i = 0; i <= n; i++){
		j = i;
		while(j > 0){
			if(i>=j%10){
				dp[i] = min(dp[i],1+dp[i-j%10]);
			}
			j /= 10;
		}
	}
	cout << dp[n] << nline;
}