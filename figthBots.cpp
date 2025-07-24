#include <bits/stdc++.h>
using namespace std;


void solve(vector<vector<int>>& matrix){
    int n = matrix.size();
    int layers = (n-1)/2+1;
    for(int k=0; k<layers; k++){
        vector<int> v;
        for(int i=k; i<=n-k-1; i++){
            v.push_back(matrix[i][k]);
        }
        for(int j=k+1; j<=n-k-1; j++){
            v.push_back(matrix[n-k-1][j]);
        }
        for(int i = n-k-2; i>=k; i--){
            v.push_back(matrix[i][n-k-1]);
        }
        for(int j=n-k-2; j>k; j--){
            v.push_back(matrix[k][j]);
        }
        sort(v.begin(),v.end());
        int idx = 0;
        for(int i=k; i<n-k; i++){
            matrix[i][k] = v[idx];
            idx++;
        }
        for(int j=k+1; j<n-k; j++){
            matrix[n-k-1][j] = v[idx];
            idx++;
        }
        for(int i = n-k-2; i>=k; i--){
            matrix[i][n-k-1] = v[idx];
            idx++;
        }
        for(int j=n-k-2; j>k; j--){
            matrix[k][j] = v[idx];
            idx++;
        }
    }
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cout<<matrix[i][j]<<" ";
        }
        cout<<endl;
    }
}

int main() {
    int n;
    cin>>n;
    vector<vector<int>> v1(n,vector<int>(n));
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin>>v1[i][j];
        }
    }
    solve(v1);
}
