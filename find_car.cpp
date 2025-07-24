#include <iostream>
#include <cmath>

using namespace std;

void solve(int r) {
    int cnt = 0;
    for(int x = 1; x <= r; x++) {
        for(int y = 1; y <= r; y++) {
            double dist = sqrt(x * x + y * y);
            if(dist >= r && dist < r + 1) {
                cnt++;
            }
        }
    }
    cnt = cnt * 4 + 4;
    cout << cnt << "\n";
}

int main() {
    int tc;
    cin >> tc;
    while(tc--) {
        int r;
        cin >> r;
        solve(r);
    }
}
