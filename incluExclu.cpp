#include<bits/stdc++.h>
#define ff first
#define ss second
#define vii vector<pair<int,int>>
using namespace std;

int m, n;

int infected[101][101];

int sz[101][101];

vector<vii> par(101,vii(101));

map<int,int> movements = {
    {0,1},{0,-1},{1,0},{-1,0}
};

void make(int i, int j){
    par[i][j] = {i,j};
    sz[i][j] = 1;
}

pair<int,int> find(int i, int j){
    if(par[i][j] == make_pair(i,j)) return {i,j};
    return par[i][j] = find(par[i][j].ff, par[i][j].ss);
}

void Union(pair<int,int> u, pair<int,int> v){
    u = find(u.ff,u.ss);
    v = find(v.ff,v.ss);
    if(u != v){
        if(sz[u.ff][u.ss] < sz[v.ff][v.ss]){
            swap(u,v);
        }
        par[v.ff][v.ss] = {u.ff,u.ss};
        sz[u.ff][u.ss] += sz[v.ff][v.ss];
    }
}

bool canPlace(int i, int j){
    return i >= 1 && j >= 1 && i <= m && j <= n;
}

void reset(){
    for(int i = 1; i <= 100; i++){
        for(int j = 1; j <= 100; j++){
            sz[i][j] = 0;
            par[i][j] = {i,j};
            infected[i][j] = 0;
        }
    }
}

void solve(){
    cin >> m >> n;
    for(int i = 1; i <= m; i++){
        for(int j = 1; j <= n; j++){
            cin >> infected[i][j];
            make(i,j);
        }
    }
    for(int i = 1; i <= m; i++){
        for(int j = 1; j <= n; j++){
            if(!infected[i][j]) continue;
            for(auto & move : movements){
                int ni = i+move.ff;
                int nj = j+move.ss;
                if(canPlace(ni,nj) && infected[ni][nj]){
                    Union({i,j},{ni,nj});
                }
            }
        }
    }
    int ans = 0;
    for(int i = 1; i <= m; i++){
        for(int j = 1; j <= n; j++){
            if(infected[i][j] && par[i][j] == make_pair(i,j)){
                pair<int,int> pr = find(i,j);
                ans = max(ans,sz[pr.ff][pr.ss]);
            }
        }
    }
    cout << ans;
    reset();
}

int main(){
    int t;
    cin >> t;
    for(int i = 1; i <= t; i++){
        solve();
        if(i != t){
            cout << endl;
        }
    }
}