#include <bits/stdc++.h>

using namespace std;

#define debug(x) cout << "[" <<  #x << " " << x << "] " << endl;

#define ar array
#define ll long long
#define ld long double
#define sz(x) ((int)x.size())
#define all(a) (a).begin(), (a).end()

typedef vector<int> vi;
typedef pair<int,int> pi;

const int MAX_N = (1 << 16);
const ll MOD = 1e9 + 7;
const ll INF = 1e9;
const ld EPS = 1e-9;


void solve() {
    int n, m;
    cin >> n >> m;

    vector<int> travel_cost(n);
    vector<vector<int>> product_cost(n, vector<int>(m));

    for (int i = 0; i < n; ++i) {
        cin >> travel_cost[i];
        for (int j = 0; j < m; ++j) {
            cin >> product_cost[i][j];
        }
    }

    vector<vector<int>> dp(n + 1, vector<int>(m + 1, INT_MAX));
    dp[0][0] = 0;

    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= m; j++) {
            // Don't buy any products from warehouse i
            dp[i][j] = dp[i - 1][j] + travel_cost[i - 1];

            for (int k = 1; k <= min(j, m); k++) {
                // Try buying k products from warehouse i
                dp[i][j] = min(dp[i][j], dp[i - 1][j - k] + product_cost[i - 1][k - 1]);
            }
        }
    }

    // Find the minimum cost for buying all products from any combination of warehouses
    int min_cost = INT_MAX;
    for (int i = 0; i <= n; i++) {
        min_cost = min(min_cost, dp[i][m]);
    }

    cout <<  min_cost << "\n";

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
