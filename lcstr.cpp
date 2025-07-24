#include<iostream>
#include<queue>
#include<map>
#include<set>
#include<vector>
#include<string>
using namespace std;

const int maxN = 2e5+5;
const int MOD = 1e9+7;
const int INF = 1e9+5;

int lcs(int i, int j, string& s1, string& s2){
	int ans = 0;
	ans = max(ans,lcs(i-1,j,s1,s2));
	ans = max(ans,lcs(i,j-1,s1,s2));
	int toCal = 0;
	while(true){
		toCal += s1[i] == s2[j];
		i--;
		j--;
		if(s1[i] != s2[j]) break;
	}
	ans = max(toCal,ans);
}