#include <bits/stdc++.h>

using namespace std;

#define debug(x) cout << "[" <<  #x << " " << x << "] ";

#define ar array
#define ll long long
#define ld long double
#define sz(x) ((int)x.size())
#define all(a) (a).begin(), (a).end()

typedef vector<int> vi;
typedef pair<int,int> pi;

const int MAX_N = 1e6 + 5;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;
const ld EPS = 1e-9;

ll dp[2][3][MAX_N];

void solve() {
    int n,m;
    cin >> n >> m;
    dp[0][1][1] = dp[1][1][1] = dp[0][2][2] = dp[1][2][2] = 1LL;
    for(int i=2; i<max(m,n)+1; i++){
        dp[0][1][i] = (dp[0][1][i] + dp[1][2][i-1] + dp[1][1][i-1])%MOD;
        dp[0][2][i] = (dp[0][2][i] + dp[1][2][i-2] + dp[1][1][i-2])%MOD;
        dp[1][1][i] = (dp[1][1][i] + dp[0][2][i-1] + dp[0][1][i-1])%MOD;
        dp[1][2][i] = (dp[1][2][i] + dp[0][1][i-2] + dp[0][2][i-2])%MOD;
    }
    ll ans1 = (dp[0][1][m] + dp[0][2][m] + dp[1][1][m] + dp[1][2][m])%MOD;
    ll ans2= (dp[0][1][n] + dp[0][2][n] + dp[1][1][n] + dp[1][2][n])%MOD;
    cout << (ans1 + ans2 - 2)%MOD;
}


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tc = 1;
    for (int t = 1; t <= tc; t++) {
        // cout << "Case #" << t << ": ";
        solve();
    }
}
