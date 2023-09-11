#include <bits/stdc++.h>
#include <iostream>

using namespace std;

#define debug(x) cout << "[" <<  #x << " " << x << "] ";

#define ar array
#define int long long
#define ld long double
#define sz(x) ((int)x.size())
#define all(a) (a).begin(), (a).end()


 
 
void solve() {
    int n;
    cin >> n;
    int l = 0, r = min<int>(2e9, 2 * n);
    while (r - l > 1) {
        int m = (l + r) >> 1;
        // m = x + y, answer = x + 2 * y
        if (m * (m - 1) / 2 + m < n) {
            l = m;
        } else {
            r = m;
        }
    }
    int y = n - r * (r - 1) / 2;
    if ((r + 1) * r / 2 <= n) {
        cout << min(r + y, r + 1 + n - (r + 1) * r / 2) << "\n";
    } else {
        cout << r + y << "\n";
    }
}


int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tc = 1;
    cin >> tc;
    for (int t = 1; t <= tc; t++) {
        // cout << "Case #" << t << ": ";
        solve();
    }
}
