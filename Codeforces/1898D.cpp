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
ll a[MAX_N];
ll b[MAX_N];


void solve() {
    int n;
    cin >> n;
    for(int i=0; i<n; i++)cin >> a[i];
    for(int i=0; i<n; i++)cin >> b[i];

    ll ans = 0;
    ll mx = 0;
    ll mn = 1e9;
    for(int i=0; i<n; i++){
        mx = max(mx,min(a[i],b[i]));
        mn = min(mn, max(a[i],b[i]));
        ans += abs(a[i] - b[i]);
    }
    ans += 2*max(0LL, mx - mn);
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
