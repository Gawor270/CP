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
    ll n;
    cin >> n;
    ll ans = 0;
    map<int,ll> up,side, diag1, diag2;

    for(int i=0; i<n; i++){
        int x,y;
        cin >> x >> y;
        up[x]++;
        side[y]++;
        diag1[x-y]++;
        diag2[x+y]++;
    }
    
    for(auto n : up)ans += (n.second)*(n.second-1);
    for(auto n : side)ans += (n.second)*(n.second-1);
    for(auto n : diag1)ans += (n.second)*(n.second-1);
    for(auto n : diag2)ans += (n.second)*(n.second-1);
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
