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

const int MAX_N = 2e5 + 5;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;
const ld EPS = 1e-9;

int dp[MAX_N];
int last[MAX_N];

void solve() {
    int n;
    cin >> n;
    memset(dp,1e9,(n+1)*sizeof(int));
    for(int i=1; i<=n; i++){
        last[i] = 1e9; 
    }

    for(int i=1; i<=n; i++){
        int inp;
        cin >> inp;
        dp[i] = min(dp[i-1]+1, last[inp]);
        last[inp] = min(last[inp], dp[i-1]); 
    }
    cout << n -dp[n] << "\n";
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
