#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;

template<class T> using ordered_set =tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update> ;

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

int dp[MAX_N][4];

void solve() {
    int n;
    cin >> n;
    memset(dp,0, n*4*sizeof(int) );
    vi b(n);
    for(auto&x : b)cin >> x;

    for(int i=0; i<n; i++){
        if(i){
            dp[i][1] = max(dp[i-1][1] -1, b[i] -1);
            dp[i][2] = max(dp[i-1][2] -1, dp[i-1][1] + b[i] -1);
            dp[i][3] = max(dp[i-1][3], dp[i-1][2] + b[i] -1);
        } else {
            dp[i][1] = b[i] - 1;
        }
    }

    cout << dp[n-1][3]+1 << "\n";

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
