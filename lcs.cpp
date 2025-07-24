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

string dp[3001][3001];

string func2(int i, int j, string &s1, string &s2){
	if(i < 0 || j < 0) return "";
	if(dp[i][j][0] != '$') return dp[i][j];
	string ans = func2(i-1,j,s1,s2);
	string s3 = func2(i,j-1,s1,s2);
	if(s3.size() > ans.size()){
		ans = s3;
	}
	if(s1[i] == s2[j]){
		string s5 = func2(i-1,j-1,s1,s2)+s1[i];
		if(s5.size() > ans.size()){
			ans = s5;	
		} 
	}
	return dp[i][j] = ans;
}

int main(){
	string s1, s2;
	cin >> s1 >> s2;
	int l1 = s1.size()-1;
	int l2 = s2.size()-1;
	for(int i = 0; i <= l1; i++){
		for(int j = 0; j <= l2; j++){
			dp[i][j] = "$";
		}
	}
	cout << func2(l1,l2,s1,s2) <<"\n";
}