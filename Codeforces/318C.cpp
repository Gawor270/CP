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

const int MAX_N = 2e5 + 5;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;
const ld EPS = 1e-9;

ll both_positive(ll a, ll b, ll m) {
    ll steps = 0;
    while(a < m && b < m){
        a += b;
        swap(a,b);
        steps++;
    }
    return steps;
}

void solve() {
    ll x,y,m;
    cin >> x >> y >> m;

    if (x >= m || y >= m){
        cout << 0 << "\n";
        return;
    }
    if (x <= 0 && y <= 0) {
        cout << -1 << "\n";
        return;
    }

    if (x > y)swap(x,y);
    ll diff = min(m,0LL) - min(x,0LL);
    ll steps = diff/y + (diff%y > 0);
    x += steps*y;

    cout << steps + both_positive(x,y,m) << "\n";
}




int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tc = 1;
    // cin >> tc;
    for (int t = 1; t <= tc; t++) {
        // cout << "Case #" << t << ": ";
        solve();
    }
}
