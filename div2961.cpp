#include <bits/stdc++.h>
#define ff first
#define ss second
#define pb push_back
#define all(v) (v).begin(),(v).end()

using namespace std;

int main() {
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        map<int,int> mp1;
        for(int i = 0; i < n; i++){
            int x;
            cin >> x;
            mp1[x]++;
        }
        vector<int> v1;
        for(auto & pr: mp1){
            v1.pb(pr.ss);
        }
        sort(all(v1));
        reverse(all(v1));
        int sum = 0, mxK = 0;
        for(int i = 1; i <= v1.size(); i++){
            sum += v1[i-1];
            mxK = max(mxK,(sum/i)*(i));
        }
        cout << mxK << endl;
    }
}
