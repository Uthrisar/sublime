#include<bits/stdc++.h>
using namespace std;

int dp[5005][5005];

int func(int i, int j, string &s1, string &s2){
	if(i == 0) return j;
	if(j == 0) return i;
	if(dp[i][j] != -1) return dp[i][j];
	if(s1[i-1] == s2[j-1]){
		return dp[i][j] = func(i-1,j-1,s1,s2);
	} else {
		return dp[i][j] = 1+min(min(func(i,j-1,s1,s2),func(i-1,j,s1,s2)),func(i-1,j-1,s1,s2));
	}
}

int main(){
	string s1, s2;
	cin >> s1 >> s2;
	memset(dp,-1,sizeof(dp));
	cout << func(s1.length(),s2.length(), s1, s2) <<"\n";
}