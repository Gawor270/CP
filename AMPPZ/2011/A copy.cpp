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

const int MAX_N = 1e5 + 5;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;
const ld EPS = 1e-9;

void solve() {
    int n,m;
    cin >> n >> m;

    vector grid(n,vector<int>(m));
    vector dp(n,vector<int>(m,1));
    int ans = 0;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin >> grid[i][j];
        }
    }

    for(int i=1; i<n; i++){
        for(int j=1; j<m;j ++){
            if(grid[i][j] - grid[i-1][j] == grid[i][j] - grid[i][j-1]){
                dp[i][j] = min(dp[i-1][j], dp[i][j-1]);
                dp[i][j] = min(dp[i][j], dp[i-1][j-1])+1;
            }
            ans = max(ans, dp[i][j]);
        }
    }

    cout << ans << "\n";
}


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tc = 1;
    cin >> tc;
    for (int t = 1; t <= tc; t++) {
        // cout << "Case #" << t << ": ";
        solve();
    }
}
