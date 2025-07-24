#include<bits/stdc++.h>
using namespace std;

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N, K;
        cin >> N >> K;
        int min_required_length = (K * (K + 1))/2 + K - 1;
        if (min_required_length > N) {
            cout << "NO" << endl;
        } else {
            cout << "YES" << endl;
        }
    }
}
