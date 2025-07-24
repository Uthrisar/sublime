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

#define nline "\n"
#define ll long long 
#define pi pair<int,int>
#define si set<int>
#define vi vector<int>
#define vl vector<ll>
#define mi map<int,int>
#define msi multiset<int>
#define maxHeap priority_queue<int>
#define minHeap priority_queue<int,vector<int>,greater<int>>

using namespace std;

const int N = 2e5+5;
const int M = 1e9+7;
const int INF = 1e9+5;

vector<int> graph[N];
bool vis[N];

int subtree_sum[N];
bool is_prime[N];

void dfs(int v, int par = 0){
    if(is_prime[v]) subtree_sum[v] = 1;
    else subtree_sum[v] = 0;
    for(int child : graph[v]){
        if(child == par) continue;
        dfs(child, v);
        subtree_sum[v] += subtree_sum[child];
    }
}

int main(){
    int n;
    cin >> n;
    for(int i = 0; i < n-1; i++){
        int x, y;
        cin >> x >> y;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }
    for(int i = 2; i <= n; i++){
        is_prime[i] = true;
    }

    is_prime[1] = false;
    for(int i = 2; i <= n; i++){
        if(is_prime[i]){
            for(int j = 2*i; j <= n; j += i){
                is_prime[j] = false;
            }
        }
    }

    dfs(1);
    int ans = 0;
    // int node;
    for(int i = 2; i <= n; i++){
        int part1 = subtree_sum[i];
        int part2 = subtree_sum[1]-part1;
        if(ans < part1*part2){
            ans = part1*part2;
            // node = i;
        }
    }
    cout << ans;
}