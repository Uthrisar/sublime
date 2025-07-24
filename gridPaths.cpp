#include <bits/stdc++.h>
#define ff first
#define ss second
using namespace std;

vector<pair<int,int>> moves = {
	{0,1},{-1,0},{0,-1},{1,0}
};

bool vis[7][7];

bool is_valid(int x, int y){
	return (x >= 0 && y >= 0 && x < 7 && y < 7 && !vis[x][y]);
}

string s;

int dfs(int ind, int x, int y){
	if(ind == 48){
		return (x == 6 && y == 0);
	}
	int ans = 0;
	if(s[ind] == '?'){
		for(auto& move : moves){
			if(is_valid(x+move.ff, y+move.ss)){
				vis[x+move.ff][y+move.ss] = true;
				ans += dfs(ind+1,x+move.ff,y+move.ss);
				vis[x+move.ff][y+move.ss] = false;
			}
		}
	} else if(s[ind] == 'R'){
		if(is_valid(x,y+1)){
			vis[x][y+1] = true;
			ans += dfs(ind+1,x,y+1);
			vis[x][y+1] = false;
		}
	} else if(s[ind] == 'U'){
		if(is_valid(x-1,y)){
			vis[x-1][y] = true;
			ans += dfs(ind+1,x-1,y);
			vis[x-1][y] = false;
		}
	} else if(s[ind] == 'L'){
		if(is_valid(x,y-1)){
			vis[x][y-1] = true;
			ans += dfs(ind+1,x,y-1);
			vis[x][y-1] = false;
		} 
	} else {
		if(is_valid(x+1,y)){
			vis[x+1][y] = true;
			ans += dfs(ind+1,x+1,y);
			vis[x+1][y] = false;
		}
	}
	return ans;
}

int main(){
	cin >> s;
	memset(vis,false,sizeof(vis));
	vis[0][0] = true;
	cout << dfs(0,0,0);
}